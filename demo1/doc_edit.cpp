#include "doc_edit.h"
#include "ui_doc_edit.h"
#include "login.h"

doc_edit::doc_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_edit)
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

    my_port=8889;
    //sql_ip=QHostAddress("192.168.149.23");
    sql_ip=SQL_ip;
    sql_port=8888;

    // 接收数据时，需要将SOCKET与接收端口绑定在一起
    bool bindResult = m_socket->bind(my_ip, my_port);
    if(!bindResult)
    {
        QMessageBox::warning(this, tr("Waring"),
                              tr("binding self error!"),
                                 QMessageBox::Yes);
        return;
    }
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(read_data()));    //绑定接收
}

doc_edit::~doc_edit()
{
    delete ui;
    delete m_socket;
}

void doc_edit::on_pushButton_2_clicked()
{


    QString name =ui->nameEdit->text().trimmed();
    QString gender =ui->genderEdit->text().trimmed();
    QString room =ui->roomEdit->text().trimmed();
    QString contact =ui->contactEdit->text().trimmed();
    QString position =ui->positionEdit->text().trimmed();
    QString major =ui->majorEdit->text().trimmed();
    QString year =ui->yearEdit->text().trimmed();//要送到表里的数据


    QString datastr = QString(R"([
            {
                "sign":"%1",
                "username":"%2",
                "name": "%3",
                "gender": "%4",
                "room": "%5",
                "contact":"%6",
                "position":"%7",
                "major":"%8",
                "year":"%9",
                "ip":"%10",
                "port":"%11"
            }

        ])").arg(4).arg(MainUser).arg(name).arg(gender).arg(room).arg(contact).arg(position).arg(major).arg(year).arg(my_ip.toString()).arg(my_port);

     qDebug()<<datastr;
    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());
    qDebug()<<jsondoc;
    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);
    qDebug()<<"录入信息发送成功";


}

void doc_edit::read_data()
{
    qDebug()<<"录入医生信息接收成功";
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
                    QMessageBox::information(NULL,"信息","录入成功");
                    return ;
                }
                else
                {
                    QMessageBox::information(NULL,"信息","录入失败");
                    return;
                }

            }
}

void doc_edit::on_pushButton_clicked()
{
    this->close();
    this->~doc_edit();
}
