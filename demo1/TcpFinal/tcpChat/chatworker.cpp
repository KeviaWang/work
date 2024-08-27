#include "chatworker.h"
#include "protocol.h"
#include <QDebug>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QHostAddress>
#include <QDataStream>
#include <QFileInfo>
#include <QIODevice>


ChatWorker::ChatWorker(QObject *parent)
    : QThread(parent), m_hasMessage(false), m_connected(false), m_socket(new QTcpSocket(this)),m_server(new QTcpServer(this))
{
    connect(m_socket, &QTcpSocket::readyRead, this, &ChatWorker::onReadyRead);
    connect(m_socket, &QTcpSocket::connected, this, &ChatWorker::onConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &ChatWorker::onDisconnected);
    connect(m_server, &QTcpServer::newConnection, this, &ChatWorker::onNewConnection);

}

void ChatWorker::connectToServer(const QString &hostAddress, quint16 serverPort)//连接到服务器

{
    if (m_connected)
    {
        m_socket->disconnectFromHost();
    }
    else{ m_socket->connectToHost(hostAddress, serverPort);}

}
void ChatWorker::startServer(quint16 serverPort)//服务器启动

{
    if (!m_server->listen(QHostAddress::Any,serverPort) )//如果没有监听到

    {
        qDebug() << "Failed to start server on port" << serverPort<< ", error:" << m_server->errorString();
    }

    else
    {
        qDebug() << "Server listening on port" << serverPort;
    }
}

void ChatWorker::sendMessage(const QString &message, const QHostAddress &address, quint16 port)
{
    // Check if we are connected to the server
    if (m_socket->state() == QAbstractSocket::ConnectedState)
    {
        QString formattedMessage = QString("%1:%2:%3:%4").arg(Protocol::MESSAGE_TYPE).arg(address.toString()).arg(port).arg(message);

        m_socket->write(formattedMessage.toUtf8());
        m_socket->flush();
        qDebug() << "Sent message to server:" << formattedMessage;
    }
    else
    {
        qDebug() << "Not connected to the server";
    }
}

void ChatWorker::sendFile(const QString &filePath, const QHostAddress &address, quint16 port)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray fileData = file.readAll();
        QString fileName = QFileInfo(filePath).fileName();
        QString header = QString("%1%2%3%2%4%2%5").arg(Protocol::FILE_TYPE).arg(Protocol::DELIMITER).arg(fileName).arg(fileData.size());
        m_socket->write(header.toUtf8()+fileData);
        m_socket->flush();
        file.close();
        qDebug() << "Sent file to server:" << filePath;
    }
    else
    {
        qDebug() << "Failed to open file:" << filePath;
    }
}
void ChatWorker::sendFileToClient(const QString &fileName, const QByteArray &fileData, QTcpSocket *clientSocket)
{
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        QString header = QString("%1%2%3%2%4%2%5")
            .arg(Protocol::FILE_TYPE)
            .arg(Protocol::DELIMITER)
            .arg(fileName)
            .arg(fileData.size());

        clientSocket->write(header.toUtf8());
        clientSocket->write(fileData);
        clientSocket->flush();

        qDebug() << "Sent file to client:" << fileName;
    } else {
        qDebug() << "Client socket is not connected.";
    }
}


//多线程处理


void ChatWorker::onReadyRead()
{
    QByteArray rawMessage = m_socket->readAll();
    QString message = QString::fromUtf8(rawMessage);
    qDebug() << "Received raw message in onReadyRead:" << message;

    QStringList parts = message.split(Protocol::DELIMITER);
    if (parts.size() >= 3)
    {
        QString type = parts[0];
        QString senderAddress = parts[1];
        quint16 senderPort = static_cast<quint16>(parts[2].toUInt());
        //QString content = parts[3];
        //QByteArray content = rawMessage.mid(parts.join(Protocol::DELIMITER).length() + 1);
        if (type == Protocol::MESSAGE_TYPE)
        {
            QString content = parts[3];
            qDebug() << "Message type detected";

            for (QTcpSocket *clientSocket : qAsConst(m_clientSockets))
            {
                if (clientSocket->peerAddress().toString() != senderAddress || clientSocket->peerPort() != senderPort)
                {
                clientSocket->write(message.toUtf8());
                clientSocket->flush();
                }
            }
            emit messageReceived("Server received from " + senderAddress + ":" + QString::number(senderPort) + ": " + content);
        }
        else if (type == Protocol::FILE_TYPE)
        {
            QString fileName = parts[1];
            qint64 fileSize = parts[2].toLongLong();
            QByteArray fileData = rawMessage.mid(parts.join(Protocol::DELIMITER).length() + 1);
            qDebug()<<"file data";
            // 保存文件
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly)) {
            file.write(fileData);
            file.close();
            qDebug() << "File received and saved:" << fileName;
            QFile fileToSend(fileName);
            if (fileToSend.open(QIODevice::ReadOnly))
            {
                QByteArray fileDataToSend = fileToSend.readAll();
                fileToSend.close();

                // 转发文件到其他客户端
                for (QTcpSocket *clientSocket : qAsConst(m_clientSockets))
                {
                    if (clientSocket != m_socket) // 不要将文件发送回给发件人
                    {
                        sendFileToClient(fileName, fileDataToSend, clientSocket);
                    }
                }

                                emit fileReceived(fileName, fileData);
                                qDebug() << "File forwarded to other clients:" << fileName;
                            }
            else{qDebug() << "Failed to open file for forwarding:" << fileName;}
            }
            else {qDebug() << "Failed to save file:" << fileName;}
        }
    }
}
void ChatWorker::onConnected()
{
    m_connected = true;
    qDebug() << "Connected to server";
}

void ChatWorker::onDisconnected()
{
    if (m_socket->state() == QAbstractSocket::UnconnectedState) {
        m_connected = false;
        qDebug() << "Disconnected from server";
    }

    // 如果是服务器的断开连接，需要处理所有客户端
    for (QTcpSocket *clientSocket : qAsConst(m_clientSockets)) {
        clientSocket->disconnectFromHost();
        clientSocket->deleteLater();
    }
    m_clientSockets.clear();  // 清空客户端列表
}


void ChatWorker::onNewConnection()
{
    QTcpSocket *clientSocket = m_server->nextPendingConnection();
    if (clientSocket)
    {
        qDebug() << "New client connected";
        m_clientSockets.append(clientSocket);

        connect(clientSocket, &QTcpSocket::readyRead, [this, clientSocket]() {
            QByteArray message = clientSocket->readAll();
            qDebug() << "Received message from client:" << message;

            QStringList parts = QString::fromUtf8(message).split(Protocol::DELIMITER);
            if (parts.size() >= 3)
            {
                QString type = parts[0];
                if (type == Protocol::FILE_TYPE)
                {
                    QString fileName = parts[1];
                    qint64 fileSize = parts[2].toLongLong();
                    m_fileData = message.mid(parts.join(Protocol::DELIMITER).length() + 1);
                    QFile file(fileName);
                    if (file.open(QIODevice::WriteOnly))
                    {
                        file.write(m_fileData);
                        file.close();
                        emit fileReceived(fileName,m_fileData);
                        qDebug() << "File received and saved:" << fileName;
                        // 重新读取文件数据以便转发
                        QFile fileToSend(fileName);
                        if (fileToSend.open(QIODevice::ReadOnly))
                        {
                            QByteArray fileDataToSend = fileToSend.readAll();
                            fileToSend.close();

                            // 转发文件到其他客户端
                            for (QTcpSocket *otherSocket : qAsConst(m_clientSockets))
                            {
                                if (otherSocket != clientSocket)
                                {sendFileToClient(fileName, fileDataToSend, otherSocket);}
                            }

                         qDebug() << "File forwarded to other clients:" << fileName;
                         }

                    }
                    else {qDebug() << "Failed to open file for forwarding:" << fileName; }
                }
                else
                {
                    for (QTcpSocket *socket : qAsConst(m_clientSockets))
                    {
                        if (socket != clientSocket)
                        {
                            socket->write(message);
                            socket->flush();
                        }
                    }
                    emit messageReceived("Client: " + QString::fromUtf8(message));
                }
            }
        });

        connect(clientSocket, &QTcpSocket::disconnected, [this, clientSocket]() {
            clientSocket->deleteLater();
            m_clientSockets.removeAll(clientSocket);
            qDebug() << "Client disconnected";
        });
    }
}


void ChatWorker::run()
{
    while (true) {
            QMutexLocker locker(&m_mutex);
            while (!m_hasMessage) {
                m_messageCondition.wait(&m_mutex);  // 等待有消息到来
            }

            if (m_socket->state() == QAbstractSocket::ConnectedState) {
                m_socket->write(m_messageToSend.toUtf8());  // 写入消息到套接字
                m_socket->flush();  // 确保消息立即发送
            }

            m_hasMessage = false;  // 处理完消息后重置标志
        }
}
