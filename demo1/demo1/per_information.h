#ifndef PER_INFORMATION_H
#define PER_INFORMATION_H

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
class per_information;
}

class per_information : public QWidget
{
    Q_OBJECT

public:
    explicit per_information(QWidget *parent = nullptr);
    ~per_information();

private slots:
    void on_pushButton_2_clicked();
    void read_data();

    void on_pushButton_clicked();

private:
    Ui::per_information *ui;
    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    int sql_port;
    QHostAddress my_ip;
    int my_port;

};

#endif // PER_INFORMATION_H
