#include "doc_information.h"
#include "ui_doc_information.h"

doc_information::doc_information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_information)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(7);   //修改列数
    ui->tableWidget->setRowCount(1);

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

doc_information::~doc_information()
{
    delete ui;
    delete m_socket;
}
void doc_information::appendOneRow(QString name,QString gender,QString room,QString contact,QString positon,QString major,QString year)
{


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



   ui->tableWidget->setItem(0,0,nameItem);
   ui->tableWidget->setItem(0,1,genderItem);
   ui->tableWidget->setItem(0,2,roomItem);
   ui->tableWidget->setItem(0,3,contactItem);
   ui->tableWidget->setItem(0,4,posionItem);
   ui->tableWidget->setItem(0,5,majorItem);
   ui->tableWidget->setItem(0,6,yearItem);
}

void doc_information::on_pushButton_3_clicked()
{
    QString doc_name = ui->lineEdit->text();//将医生姓名和user姓名送到预约表
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

    connect(m_socket, SIGNAL(readyRead()), this, SLOT(read_data()));
    appendOneRow("mina","hot","a","s","d","r","f");
}

void doc_information::read_data()
{

}
