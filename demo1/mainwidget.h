#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include "chatworker.h"
#include <QMessageBox>
#include "protocol.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);

    ~MainWidget();

private slots:
    void on_MessageReceived(const QString &message);  // 处理接收到的消息
    void on_ConnectButton_Clicked();  // 槽函数用于连接到服务器
    void on_SendButton_Clicked();
    void on_SelectFileButton_Clicked();
    void onFileReceived(const QString &fileName, const QByteArray &fileData);  // 处理文件接收的槽函数

    void on_quitButton_clicked();

private:
    Ui::MainWidget *ui;
    ChatWorker *m_chatWorker;  // 聊天线程
};

#endif // MAINWINDOW_H
