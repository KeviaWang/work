#include "handleapment.h"
#include "ui_handleapment.h"

handleApment::handleApment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::handleApment)
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

    my_port=8891;
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
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(recvdata()));    //绑定接收
}


handleApment::~handleApment()
{
    delete ui;
    delete m_socket;
}

void handleApment::on_tijiaoBtn_clicked()
{
    QString bingli = ui->bingliEdit->text();
    QString chufang = ui->chufangEdit->text();
    QString yizhu = ui->yizhuEdit->text();
    QString jiaofei = ui->jiaofeiEdit->text();

    // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
    //          6：查看挂号信息 7：编写病例 编写处方和缴费 8：查看病例、查看处方和缴费 9：查看医生信息
    QString datastr = QString(R"([
            {
                "sign":"%1",
                "name":"%2",
                "username": "%3",
                "bingli": "%4",
                "chufang": "%5",
                "yizhu":"%6",
                "jiaofei":"%7",
                "ip":"%8",
                "port":"%9"
            }

        ])").arg(7).arg(patient_name).arg(MainUser).arg(bingli).arg(chufang).arg(yizhu).arg(jiaofei).arg(my_ip.toString()).arg(my_port);

    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());
    qDebug()<<"发送编写处方信息";
    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);

}

void handleApment::on_pushButton_clicked()
{
    this->close();
    this->~handleApment();
}
void handleApment::recvdata()
{
    qDebug()<<"接收查看医生信息成败";
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

