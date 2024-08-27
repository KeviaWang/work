#ifndef CHATWORKER_H
#define CHATWORKER_H

#include <QThread>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QMutex>
#include <QWaitCondition>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFile>


class ChatWorker : public QThread
{
    Q_OBJECT

public:
    explicit ChatWorker(QObject *parent = nullptr);

    void connectToServer(const QString &hostAddress, quint16 port);//链接

    void startServer(quint16 serverPort);

    void sendMessage(const QString &message, const QHostAddress &address, quint16 port);

    void sendFile(const QString &filePath, const QHostAddress &address, quint16 port);

    void sendFileToClient(const QString &fileName, const QByteArray &fileData, QTcpSocket *clientSocket);

    void stop();  // 停止线程

signals:
    // 信号，用于向主线程发送接收到的消息
    void messageReceived(const QString &message);
    void fileReceived(const QString &fileName, const QByteArray &fileData);

public slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();
    void onNewConnection();


protected:
    void run() override;  // 线程的执行逻辑

private:
    QString m_messageToSend;  // 存储待发送的消息

    QMutex m_mutex;
    QWaitCondition m_messageCondition;

    bool m_hasMessage;        // 标记是否有消息需要发送
    bool m_connected;
    bool m_stopRequested;  // 线程停止标志

    QTcpSocket *m_socket;  // TCP socket
    QTcpServer *m_server;  // 用于监听传入连接的 server

    QList<QTcpSocket*> m_clientSockets;
    QByteArray m_fileData;

};

#endif // CHATWORKER_H
