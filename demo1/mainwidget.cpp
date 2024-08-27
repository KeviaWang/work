#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "chatworker.h"
#include <QDebug>
#include <QTcpSocket>
#include <QFileDialog>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MainWidget),
      m_chatWorker(new ChatWorker(this))
{

    ui->setupUi(this);

    ui->textDisplay->setReadOnly(true);  // 文本框设置为只读

    // 连接信号和槽

    connect(m_chatWorker, &ChatWorker::messageReceived,
            this, &MainWidget::on_MessageReceived);
    connect(m_chatWorker, &ChatWorker::fileReceived,
               this, &MainWidget::onFileReceived);  // 连接文件接收信号
    connect(ui->connectButton, &QPushButton::clicked,
                this, &MainWidget::on_ConnectButton_Clicked);  // 连接按钮
    connect(ui->sendButton, &QPushButton::clicked,
                this, &MainWidget::on_SendButton_Clicked);
    connect(ui->SelectFileButton, &QPushButton::clicked,
                this, &MainWidget::on_SelectFileButton_Clicked);
    connect(ui->quitButton, &QPushButton::clicked, this, &MainWidget::on_quitButton_clicked);

    m_chatWorker->start();  // 启动聊天线程
}

MainWidget::~MainWidget()
{
    m_chatWorker->quit();
    m_chatWorker->wait();
    delete ui;
}



void MainWidget::on_ConnectButton_Clicked()
{
    QString ipAddress = QString("192.168.159.68");  // 从输入框中获取 IP 地址
    quint16 sendPort = 12345;  // 从输入框中获取发送端口
    quint16 rcvPort =  36542;  // 从输入框中获取接收端口

    if (sendPort > 0 && rcvPort > 0)
    {
            if (ipAddress.isEmpty())
            {
                // 启动服务器
                m_chatWorker->startServer(rcvPort);//监听

            }
            else
            {
                // 连接到服务器
                m_chatWorker->connectToServer(ipAddress, sendPort);
                // 隐藏接收端口编辑框
                ui->rcvEdit->hide();
                ui->sendEdit->hide();
                ui->ipEdit->hide();
                ui->connectButton->hide();
            }
    }
    else {qDebug() << "Invalid port";}
}

// 选择文件并发送
void MainWidget::on_SelectFileButton_Clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select File");
    if (!filePath.isEmpty())
    {
        QString ipAddress = ui->ipEdit->text();
        quint16 port = ui->sendEdit->text().toUInt();
        if (!ipAddress.isEmpty() && port > 0)
        {
            QHostAddress address(ipAddress);
            m_chatWorker->sendFile(filePath, address, port);
        }
    }
}

void MainWidget::onFileReceived(const QString &fileName, const QByteArray &fileData)
{
    qDebug() << "File received:" << fileName;

    // 获取文件保存路径，通常你可以选择一个保存对话框或固定路径
    QString savePath = QFileDialog::getSaveFileName(this, "Save File As", fileName);

    if (savePath.isEmpty()) {
        qDebug() << "File save canceled";
        return;
    }

    // 读取文件内容
    QFile file(savePath);
    if (file.open(QIODevice::WriteOnly)) {
        // 假设在某个地方已经将文件内容保存到 QByteArray fileData
        // 需要确保在实际代码中获取到文件的实际数据
        file.write(fileData);
        file.close();
        qDebug() << "File saved successfully to:" << savePath;
    } else {
        qDebug() << "Failed to save file:" << savePath;
    }
}

void MainWidget::on_MessageReceived(const QString &message)
{
    qDebug() << "Message received in MainWidget:" << message;
    ui->textDisplay->append(message);  // 显示接收到的消息
}

void MainWidget::on_SendButton_Clicked()
{
    QString message = ui->inputField->text();
    QString ipAddress = ui->ipEdit->text();
    quint16 port = ui->sendEdit->text().toUInt();

    if (!message.isEmpty() && !ipAddress.isEmpty() && port > 0) {
        QHostAddress address(ipAddress);
        m_chatWorker->sendMessage(message, address, port);
        ui->inputField->clear();
    }
}

void MainWidget::on_quitButton_clicked()
{
    // 断开连接
    m_chatWorker->disconnect();
    // 关闭窗口
    close();
}

