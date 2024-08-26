#include "viewapment.h"
#include "ui_viewapment.h"
#include "platform.h"
#include "handleapment.h"

viewApMent::viewApMent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewApMent)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(4);

    QStringList hlist;
    hlist << "name";
    hlist << "gender";
    hlist << "birth";
    hlist << "height";
    hlist << "weight";
    hlist << "disease";
    hlist << "famalily_history";

    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充列的宽度
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->resizeRowsToContents();


    m_socket=new QUdpSocket(this);
    //获得本机ip
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol &&
            address != QHostAddress::LocalHost) {
            my_ip = address;
            break;
        }
    }

    qDebug()<<"my ip "<<my_ip<<endl;
    my_port=8888;
    sql_ip=QHostAddress("192.168.254.129");
    sql_port=8888;

    //接受数据绑定
    m_socket->bind(my_ip,my_port);
    bool bindResult=connect(m_socket,SIGNAL(readyRead()),this,SLOT(read_data()));
    if(!bindResult)
    {
        QMessageBox::warning(this, tr("Waring"),
                              tr("binding error!"),
                                 QMessageBox::Yes);
        return; //退出
    }
}

void viewApMent::appendOneRow(int row,QString name,QString gender,QString birth,QString height,QString weight,QString disease,QString family_history)
{


   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * genderItem=new QTableWidgetItem(gender);
   QTableWidgetItem * birthItem=new QTableWidgetItem(birth);
   QTableWidgetItem * heightItem=new QTableWidgetItem(height);
   QTableWidgetItem * weightItem=new QTableWidgetItem(weight);
   QTableWidgetItem * diseaseItem=new QTableWidgetItem(disease);
   QTableWidgetItem * family_historyItem = new QTableWidgetItem(family_history);

   nameItem->setTextAlignment(Qt::AlignCenter);
   genderItem->setTextAlignment(Qt::AlignCenter);//居中
   birthItem->setTextAlignment(Qt::AlignCenter);
   heightItem->setTextAlignment(Qt::AlignCenter);
   weightItem->setTextAlignment(Qt::AlignCenter);
   diseaseItem->setTextAlignment(Qt::AlignCenter);
   family_historyItem->setTextAlignment(Qt::AlignCenter);

   ui->tableWidget->setItem(row,0,nameItem);
   ui->tableWidget->setItem(row,1,genderItem);
   ui->tableWidget->setItem(row,2,birthItem);
   ui->tableWidget->setItem(row,3,heightItem);
   ui->tableWidget->setItem(row,4,weightItem);
   ui->tableWidget->setItem(row,5,diseaseItem);
   ui->tableWidget->setItem(row,6,family_historyItem);

}



viewApMent::~viewApMent()
{
    delete ui;
}

void viewApMent::on_pushButton_2_clicked()
{
    // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
    //          6：查看挂号信息 7：编写病例 编写处方和缴费 8：查看病例、查看处方和缴费 9：查看医生信息
    QString sign;
    sign="6";
    QString datastr = QString(R"([
            {
                "sign":"%1","username":"%2","ip":"%3","port":"%4"
            }

        ])").arg(sign).arg(MainUser).arg(my_ip.toString()).arg(my_port);

    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());

    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(recvdata()));

}

void viewApMent::on_goutong_clicked()
{
    platform * plat = new platform;
    plat->show();
}

void viewApMent::on_chufangyizhu_clicked()
{
    handleApment * hand = new handleApment;
    hand->show();
}

void viewApMent::read_data()
{

    //接受数据库传来的信息
        QString name="aaa";
        QString gender="b";
        QString birth="c";
        QString height="d";
        QString weight="e";
        QString disease="f";
        QString family_history="g";
    //读取udp socket的数据缓冲区，接收数据
        while(m_socket->hasPendingDatagrams())
        {
            QByteArray datagram;
            datagram.resize(m_socket->pendingDatagramSize());

        //读取缓冲区数据并显示
            m_socket->readDatagram(datagram.data(), datagram.size());

            QJsonDocument jsonDoc = QJsonDocument::fromJson(datagram);
            QJsonArray  datagram_array=jsonDoc.array();
            int size = datagram_array.size();

            for (int i = 0; i < size; ++i)
            {
                QJsonObject jsonObject = datagram_array[i].toObject();
                // 处理jsonObject
                // 例如，打印出所有键值对
                /*for (QString key : jsonObject.keys()) {
                    qDebug() << key << ": " << jsonObject.value(key).toString();*/
                 name=jsonObject["name"].toString();
                 gender=jsonObject["gender"].toString();
                 birth=jsonObject["birth"].toString();
                 height=jsonObject["height"].toString();
                 weight=jsonObject["weight"].toString();
                 disease=jsonObject["disease"].toString();
                 family_history=jsonObject["family_history"].toString();

                 appendOneRow(i,name,gender,birth,height,weight,disease,family_history);

               }
            }

}

void viewApMent::on_pushButton_clicked()
{
    this->close();
    this->~viewApMent();
}
