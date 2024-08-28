#include "doc_information.h"
#include "ui_doc_information.h"


doc_information::doc_information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_information)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(7);   //修改列数
    ui->tableWidget->setRowCount(10);

    QStringList hlist;
    hlist << "姓名";
    hlist << "性别";
    hlist << "科室";
    hlist << "联系方式";
    hlist << "职位";
    hlist << "专业领域";
    hlist << "工作年限";

    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充列的宽度

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
    my_port=8890;
    //sql_ip=QHostAddress("192.168.149.23");
    sql_ip=SQL_ip;
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

doc_information::~doc_information()
{
    delete ui;
    delete m_socket;
}
void doc_information::appendOneRow(int row,QString name,QString gender,QString room,QString contact,QString positon,QString major,QString year)
{

    qDebug()<<"展示";
   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * genderItem=new QTableWidgetItem(gender);
   QTableWidgetItem * roomItem=new QTableWidgetItem(room);
   QTableWidgetItem * contactItem=new QTableWidgetItem(contact);
   QTableWidgetItem * posionItem=new QTableWidgetItem(positon);
   QTableWidgetItem * majorItem=new QTableWidgetItem(major);
   QTableWidgetItem * yearItem=new QTableWidgetItem(year);

   nameItem->setTextAlignment(Qt::AlignCenter);
   genderItem->setTextAlignment(Qt::AlignCenter);//居中
   roomItem->setTextAlignment(Qt::AlignCenter);
   contactItem->setTextAlignment(Qt::AlignCenter);
   posionItem->setTextAlignment(Qt::AlignCenter);
   majorItem->setTextAlignment(Qt::AlignCenter);
   yearItem->setTextAlignment(Qt::AlignCenter);

    qDebug()<<nameItem;

   ui->tableWidget->setItem(row,0,nameItem);
   ui->tableWidget->setItem(row,1,genderItem);
   ui->tableWidget->setItem(row,2,roomItem);
   ui->tableWidget->setItem(row,3,contactItem);
   ui->tableWidget->setItem(row,4,posionItem);
   ui->tableWidget->setItem(row,5,majorItem);
   ui->tableWidget->setItem(row,6,yearItem);
}

void doc_information::on_pushButton_3_clicked()
{
    QString doc_name = ui->lineEdit->text();//将医生姓名和user姓名送到预约表
    Guahao *guahao=new Guahao;
    guahao->doctor_name=doc_name;
    guahao->show();

}

void doc_information::on_pushButton_2_clicked()
{

    // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
    //          6：查看挂号信息 7：编写病例 编写处方和缴费 8：查看病例、查看处方和缴费 9：查看医生信息 10：进行挂号
    //发送信息，要求数据库传送过来表中所需的数据
    QString sign;
    sign="9";
    QString datastr = QString(R"([
            {
                "sign":"%1","username":"%2","ip":"%3","port":"%4"
            }

        ])").arg(sign).arg(MainUser).arg(my_ip.toString()).arg(my_port);

    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());

    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);
    qDebug()<<"发送查看医生信息";
    //绑定发送信号槽
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(read_data()));

}

void doc_information::read_data()
{
    qDebug()<<"接收医生资料信息";
    //接受数据库传来的信息
        QString name="aaa";
        QString gender="b";
        QString room="c";
        QString contact="d";
        QString position="e";
        QString major="f";
        QString year="g";
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
            qDebug()<<size;
            for (int i = 0; i < size; ++i)
            {
                QJsonObject jsonObject = datagram_array[i].toObject();
                // 处理jsonObject
                // 例如，打印出所有键值对
                for (QString key : jsonObject.keys()) {
                    qDebug() << key << ": " << jsonObject.value(key).toString();}
                 name=jsonObject["name"].toString();
                 gender=jsonObject["gender"].toString();
                 room=jsonObject["room"].toString();
                 contact=jsonObject["contact"].toString();
                 position=jsonObject["position"].toString();
                 major=jsonObject["major"].toString();
                 year=jsonObject["year"].toString();
                 qDebug()<<name;
                 appendOneRow(i,name,gender,room,contact,position,major,year);

               }
            }

}

void doc_information::on_pushButton_clicked()
{
    this->close();
    this->~doc_information();

}
