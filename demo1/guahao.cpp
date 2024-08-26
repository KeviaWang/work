#include "guahao.h"
#include "ui_guahao.h"

#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>

Guahao::Guahao(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Guahao)
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

    my_port=8888;
    sql_ip=QHostAddress("192.168.254.129");
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

   /* // 初始化数据库连接
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("timeslot.db"); // 确保数据库路径正确

    if (!db.open()) {
        QMessageBox::critical(this, "数据库错误", "无法连接到数据库：" + db.lastError().text());
        return;
    }*/

    // 连接日期选择器的信号到槽函数
    connect(ui->dateEdit, &QDateEdit::dateChanged, this, &Guahao::onDateChanged);
    // 初始填充 ComboBox
    onDateChanged();  // 默认情况下加载当前日期的可用时间段
}

Guahao::~Guahao()
{
    delete ui;
    delete m_socket;
}

void Guahao::onDateChanged()
{
    populateComboBox();  // 先清空并重新填充 ComboBox
}

void Guahao::populateComboBox()
{
    // 清空 ComboBox 的所有选项
    ui->comboBox->clear();

    // 添加一个空白项作为默认值
    ui->comboBox->addItem("");

    // 添加时间段到 ComboBox
    ui->comboBox->addItem("9:00~10:00");
    ui->comboBox->addItem("10:00~11:00");
    ui->comboBox->addItem("14:00~15:00");
    ui->comboBox->addItem("15:00~16:00");
}


void Guahao::on_pushButton_clicked()
{
    // 禁用按钮以防止重复点击
    ui->pushButton->setEnabled(false);

    // 获取选择的日期和时间段
    QString selectedDate = ui->dateEdit->date().toString();
    QString selectedSlot = ui->comboBox->currentText();

    if (selectedSlot.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择一个时间段！");
        ui->pushButton->setEnabled(true);  // 重新启用按钮
        return;
    }

    // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
    //          6：查看挂号信息 7：编写病例 编写处方和缴费 8：查看病例、查看处方和缴费 9：查看医生信息 10：进行挂号
    QString sign;
    QString datastr = QString(R"([
            {
                "sign":"%1",
                "username":"%2",
                "doctor_name": "%3",
                "date": "%4",
                "time": "%5",
                "ip":"%6",
                "port":"%7"
            },

        ])").arg(10).arg(MainUser).arg(doctor_name).arg(selectedDate).arg(selectedSlot).arg(my_ip.toString()).arg(my_port);

    QJsonDocument jsondoc=QJsonDocument::fromJson(datastr.toUtf8());
    //转换成QByterarray发送
    QByteArray datagram=jsondoc.toJson();
    m_socket->writeDatagram(datagram, sql_ip, sql_port);


}
void Guahao::read_data()
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
            QMessageBox::information(this, "成功", "预约成功！");
            return ;
        }
        else
        {
            QMessageBox::critical(this, "错误", "插入失败");
             ui->pushButton->setEnabled(true);  // 重新启用按钮
            return;
        }

    }
}
