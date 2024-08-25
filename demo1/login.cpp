#include "login.h"
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
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    m_socket=new QUdpSocket(this);
    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
    my_ip = info.addresses().first();
    my_port=8888;
    sql_ip=QHostAddress("192.168.254.129");
    sql_port=8888;


}

login::~login()
{
    delete ui;
    delete m_socket;
}



void login::on_signup_btn_clicked()
{
    this->close();
    signup *s = new signup;
    s->show();
}

void login::on_logBtn_clicked()
{

    //接受数据绑定
    m_socket->bind(my_ip,my_port);
    bool bindResult=connect(m_socket,SIGNAL(readyRead()),this,SLOT(read_data()));
    if(!bindResult)
    {
        QMessageBox::warning(this, tr("Waring"),
                              tr("binding error!"),
                                 QMessageBox::Yes);
        return;
    }

    QString username =ui->userLineEdit->text().trimmed();
    QString password =ui->passLineEdit->text();
    // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
    //          6：查看挂号信息 7：编写病例 8：编写处方和缴费 9：查看病例 10：查看处方和缴费 11：查看医生信息 12：医生端获取患者ip
    //          13：患者端获取医生ip
    QString sign;
    if(ui->doctorButton->isChecked())
    sign="2";
    else
    sign="3";

    //向数据库发送数据
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9); // 设置QDataStream的版本
    out << sign<<username << password<<my_ip.toString()<<QString(my_port);

    m_socket->writeDatagram(datagram,sql_ip,sql_port);



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
                QString MainUser=ui->userLineEdit->text().trimmed();
                if(ui->doctorButton->isChecked())
                {
                QMessageBox::information(NULL,"信息","登录成功");
                this->close();
                docMain docM;
                docM.show();

                }
                else
                {
                QMessageBox::information(NULL,"信息","登录成功");

                this->close();
                MainWindow *w = new MainWindow;
                w->show();
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
