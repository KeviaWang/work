#include "disease.h"
#include "ui_disease.h"
#include <QTextEdit>
#include <QApplication>
#include <QTableWidget>

disease::disease(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::disease)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(6);   //修改列数
    ui->tableWidget->setRowCount(1);

    QStringList hlist;
    hlist << "name";
    hlist << "disease";
    hlist << "doctor";
    hlist << "prescription";
    hlist << "money";
    hlist << "advice";


    ui->tableWidget->setRowHeight(0, 200);

    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setColumnWidth(5,300);

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
    my_port=9000;
    sql_ip=QHostAddress("192.168.149.23");
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

disease::~disease()
{
    delete ui;
    delete m_socket;
}

void disease::appendOneRow(QString name,QString dise,QString doctor,QString prescription,QString money,QString advice)
{


   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * diseItem=new QTableWidgetItem(dise);
   QTableWidgetItem * doctorItem=new QTableWidgetItem(doctor);
   QTableWidgetItem * prescriptionItem=new QTableWidgetItem(prescription);
   QTableWidgetItem * moneyItem = new QTableWidgetItem(money);
   QTableWidgetItem * adviceItem=new QTableWidgetItem(advice);


   //QTextEdit *textEdit = new QTextEdit();
   //textEdit->setText(advice);
   //textEdit->setWordWrapMode(QTextOption::WordWrap); // Ensure text wraps
   //ui->tableWidget->setCellWidget(0, 5, textEdit);





   ui->tableWidget->setItem(0,0,nameItem);
   ui->tableWidget->setItem(0,1,diseItem);
   ui->tableWidget->setItem(0,2,doctorItem);
   ui->tableWidget->setItem(0,3,prescriptionItem);
   ui->tableWidget->setItem(0,4,moneyItem);
   ui->tableWidget->setItem(0,5,adviceItem);


}

void disease::on_pushButton_2_clicked()
{
    // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
    //          6：查看挂号信息 7：编写病例 编写处方和缴费 8：查看病例、查看处方和缴费 9：查看医生信息
    QString sign;
    sign="8";
    QString datastr = QString(R"([
            {
                "sign":"%1","username":"%2","ip":"%3","port":"%4"
            }

        ])").arg(sign).arg(MainUser).arg(my_ip.toString()).arg(my_port);

    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());

    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);
    qDebug()<<"发送查看患者信息信号";

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(read_data()));
}

void disease::on_pushButton_clicked()
{
    this->close();
    this->~disease();
}

void disease::read_data()
{
    qDebug()<<"接受查看患者信息";
    //"name","disease","doctor","symbol","prescription","money","多读书多看报，少吃零食多睡觉"
    //接受数据库传来的信息
        QString name="aaa";
        QString disease="b";
        QString doctor="c";
        QString prescription="e";
        QString money="f";
        QString advice="g";
    //读取udp socket的数据缓冲区，接收数据
        while(m_socket->hasPendingDatagrams())
        {
            QByteArray datagram;
            datagram.resize(m_socket->pendingDatagramSize());

        //读取缓冲区数据并显示
            m_socket->readDatagram(datagram.data(), datagram.size());

            QJsonDocument jsonDoc = QJsonDocument::fromJson(datagram);
            QJsonArray  datagram_array=jsonDoc.array();

            {
                QJsonObject jsonObject = datagram_array[0].toObject();
                // 处理jsonObject
                // 例如，打印出所有键值对
                /*for (QString key : jsonObject.keys()) {
                    qDebug() << key << ": " << jsonObject.value(key).toString();*/
                 name=jsonObject["patient_name"].toString();
                 disease=jsonObject["diagnose"].toString();
                 doctor=jsonObject["doctor_name"].toString();
                 //symbol=jsonObject["symbol"].toString();
                 prescription=jsonObject["prescription"].toString();
                 money=jsonObject["pay"].toString();
                 advice=jsonObject["advice"].toString();

                 //求数据库传送过来表中所需的数据
                  //appendOneRow("name","disease","doctor","symbol","prescription","money","多读书多看报，少吃零食多睡觉");//在这里输入传过来的信息
                  appendOneRow(name,disease,doctor,prescription,money,advice);
               }
            }

}
