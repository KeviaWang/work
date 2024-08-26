#ifndef HANDLEAPMENT_H
#define HANDLEAPMENT_H

#include <QWidget>
#include <QDialog>
#include<QWidget>
#include<QUdpSocket>
#include<QMessageBox>
#include <QHostInfo>
#include<QHostAddress>
#include<QDataStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QNetworkInterface>

#include "login.h"

namespace Ui {
class handleApment;
}

class handleApment : public QWidget
{
    Q_OBJECT

public:
    explicit handleApment(QWidget *parent = nullptr);
    ~handleApment();
    QString patient_name;

private slots:
    void on_tijiaoBtn_clicked();

    void on_pushButton_clicked();

    void recvdata();


private:
    Ui::handleApment *ui;
    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    int sql_port;
    QHostAddress my_ip;
    int my_port;
};

#endif // HANDLEAPMENT_H
