#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include<QMessageBox>
#include <QSqlDatabase>  //最后应该用不上
#include <QSqlQuery>    //最后应该用不上
#include <QSqlError>  //最后应该用不上
#include <QDebug>

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
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
    my_port=9999;
    sql_ip=QHostAddress("192.168.254.129");
    sql_port=8888;

    qDebug()<<20;
    //接受数据绑定
    bool bindResult = m_socket->bind(my_ip, my_port);
    qDebug()<<bindResult;
    if(!bindResult)
    {
        QMessageBox::warning(this, tr("Waring"),
                              tr("binding self error!"),
                                 QMessageBox::Yes);
         qDebug() << "Bind failed: " << m_socket->errorString();
        return;
    }
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(recvdata()));    //绑定接收
}

signup::~signup()
{
    qDebug()<<30;
    delete ui;
    delete  m_socket;
}

void signup::on_pushButton_2_clicked()
{
    QString username = ui->username->text().trimmed();
    QString password = ui->password->text();
    QString confirmword = ui->confirmword->text();

    if(password==confirmword)  //same
    {

        //改为向数据端发送socket
        // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
        //          6：查看挂号信息 7：编写病例 编写处方和缴费 8：查看病例、查看处方和缴费 9：查看医生信息
        QString sign;
        if(ui->doc_btn->isChecked())
        sign="0";
        else
        sign="1";


        QString datastr = QString(R"([
                {
                    "sign":"%1","username":"%2","password":"%3","ip":"%4","port":"%5"
                }

            ])").arg(sign).arg(username).arg(password).arg(my_ip.toString()).arg(my_port);

        QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());

        //转换成QByterarray发送
        QByteArray datagram=jsondoc.toJson();
        m_socket->writeDatagram(datagram, sql_ip, sql_port);


    }
    else
    {
        QMessageBox::information(this,"确定","密码不一致");
    }
}

void signup::on_pushButton_clicked()
{
    login *log = new login;
    this->close();
    this->~signup();
    log->show();
}

void signup::read_data()
{
    //读取udp socket的数据缓冲区，接收数据
    while(m_socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_socket->pendingDatagramSize());

    //读取缓冲区数据并显示
        m_socket->readDatagram(datagram.data(), datagram.size());
        QString str = datagram.data();
        if(str=="1")
        {
            QMessageBox::information(NULL,"信息","注册成功");
            return ;
        }
        else
        {
            QMessageBox::information(NULL,"信息","注册失败");
            return;
        }

    }

}
