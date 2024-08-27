#include "per_information.h"
#include "ui_per_information.h"

per_information::per_information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::per_information)
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
    my_port=8893;
    sql_ip=QHostAddress("192.168.149.23");
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

per_information::~per_information()
{
    delete ui;
    delete m_socket;
}

void per_information::on_pushButton_2_clicked()
{


    QString name = ui->lineEdit->text().trimmed();
    QString gender = ui->lineEdit_2->text().trimmed();
    QString birth = ui->lineEdit_3->text().trimmed();
    QString height = ui->lineEdit_4->text().trimmed();
    QString weight = ui->lineEdit_5->text().trimmed();
    QString contact = ui->lineEdit_6->text().trimmed();
    QString home = ui->lineEdit_7->text().trimmed();
    QString ID = ui->lineEdit_8->text().trimmed();
    QString disease = ui->lineEdit_9->text().trimmed();
    QString family_history = ui->lineEdit_10->text().trimmed();
    QString medicine_use = ui->lineEdit_11->text().trimmed();
    QString insurance = ui->lineEdit_12->text().trimmed();
    QString emergency = ui->lineEdit_13->text().trimmed();


    QString datastr = QString(R"([
            {
                "sign":"%1",
                "username":"%2",
                "name": "%3",
                "gender": "%4",
                "birth": "%5",
                "height":"%6",
                "weight":"%7",
                "contact":"%8",
                "home":"%9",
                "ID":"%10",
                "disease":"%11",
                "family_history":"%12",
                "medicine_use":"%13",
                "insurance":"%14",
                "emergency":"%15",
                "ip":"%16",
                "port":"%17"
            }

        ])").arg(5).arg(MainUser).arg(name).arg(gender).arg(birth).arg(height).arg(weight).arg(contact).arg(home)
            .arg(ID).arg(disease).arg(family_history).arg(medicine_use).arg(insurance).arg(emergency).arg(my_ip.toString()).arg(my_port);

    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());
    qDebug()<<jsondoc;
    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);
    qDebug()<<"患者个人信息发送成功";

}

void per_information::read_data()
{
     qDebug()<<"接收患者信息插入成败";
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

void per_information::on_pushButton_clicked()
{
    this->close();
    this->~per_information();
}
