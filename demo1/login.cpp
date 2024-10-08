﻿#include "login.h"
#include "ui_login.h"
#include "signup.h"
#include "docmain.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QSqlDatabase>            //最后应该用不上
#include <QSqlQuery>               //最后应该用不上
#include <QSqlError>               //最后应该用不上
#include <QDebug>

QString MainUser="user";
QHostAddress SQL_ip=QHostAddress("192.168.159.23"); //zht
//QHostAddress SQL_ip=QHostAddress("192.168.149.23"); //wxh
QString user_sign="doctor";
QString recv_sign="patient";

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
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

    my_port=8892;
    //sql_ip=QHostAddress("192.168.149.23");
    sql_ip=SQL_ip;
    sql_port=8888;

    //接受数据绑定
    bool bindResult = m_socket->bind(my_ip, my_port);
    qDebug()<<bindResult;
    if(!bindResult)
    {
        QMessageBox::warning(this, tr("Waring"),
                              tr("binding self error!"),
                                 QMessageBox::Yes);
        return;
    }


    connect(m_socket, SIGNAL(readyRead()), this, SLOT(read_data()));    //绑定接收


}

login::~login()
{
    delete ui;
    delete m_socket;
}



void login::on_signup_btn_clicked()
{
    qDebug()<<"登录按键触发";
    this->close();
    signup *s = new signup;
    this->~login();
    s->show();
}

void login::on_logBtn_clicked()
{



    QString username =ui->userLineEdit->text().trimmed();
    QString password =ui->passLineEdit->text();
    // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
    //          6：查看挂号信息 7：编写病例 编写处方和缴费 8：查看病例、查看处方和缴费 9：查看医生信息 10：进行挂号
    QString sign;
    if(ui->doctorButton->isChecked())
    {
        sign="2";
        QString user_sign="doctor";
        QString recv_sign="patient";

    }
    else
    {
        sign="3";
        QString user_sign="patient";
        QString recv_sign="doctor";
    }


    QString datastr = QString(R"([
            {
                "sign":"%1","username":"%2","password":"%3","ip":"%4","port":"%5"
            }

        ])").arg(sign).arg(username).arg(password).arg(my_ip.toString()).arg(my_port);
    qDebug()<<datastr;
    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());
    qDebug()<<jsondoc;
    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);

}

void login::read_data()
{
    while(m_socket->hasPendingDatagrams())
        {

            QByteArray datagram;
            datagram.resize(m_socket->pendingDatagramSize());

        //读取缓冲区数据并显示
            m_socket->readDatagram(datagram.data(), datagram.size());
            QString sign = datagram.data();
            if(sign=="1")
            {

                if(ui->doctorButton->isChecked())
                {
                QMessageBox::information(NULL,"信息","登录成功");

                MainUser=ui->userLineEdit->text().trimmed();

                this->close();
                docMain* docM=new docMain;
                docM->show();
                qDebug()<<"进入医生主界面";
                //this->~login(); //每次跳转都析构当前界面

                }
                else
                {
                QMessageBox::information(NULL,"信息","登录成功");
                MainUser=ui->userLineEdit->text();
                this->close();
                MainWindow *w = new MainWindow;
                qDebug()<<"进入患者主界面";
                w->show();
                //this->~login();
                }

            }
            else
            {

                QMessageBox::warning(this,tr("警告"),
                                     tr("user name or password error"),QMessageBox::Yes);
                ui->userLineEdit->clear();
                ui->passLineEdit->clear();
                ui->userLineEdit->setFocus();

            }
        }

}
