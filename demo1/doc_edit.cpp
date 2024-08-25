#include "doc_edit.h"
#include "ui_doc_edit.h"
#include "login.h"

doc_edit::doc_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_edit)
{
    ui->setupUi(this);
    m_socket=new QUdpSocket(this);
    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
    my_ip = info.addresses().first();
    my_port=8888;
    sql_ip=QHostAddress("192.168.254.129");
    sql_port=8888;
}

doc_edit::~doc_edit()
{
    delete ui;
    delete m_socket;
}

void doc_edit::on_pushButton_2_clicked()
{
    // 接收数据时，需要将SOCKET与接收端口绑定在一起
    bool bindResult = m_socket->bind(my_ip, my_port);
    if(!bindResult)
    {
        QMessageBox::warning(this, tr("Waring"),
                              tr("binding self error!"),
                                 QMessageBox::Yes);
        return;
    }
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(recvdata()));    //绑定接收

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
                "year":"%9".
                "ip":"%10",
                "port":"%11"
            },

        ])").arg(4).arg(MainUser).arg(name).arg(gender).arg(room).arg(contact).arg(position).arg(major).arg(year).arg(my_ip.toString()).arg(my_port);

    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());
    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);



}

void doc_edit::recvdata()
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
