#ifndef DISEASE_H
#define DISEASE_H

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
#include "login.h"


namespace Ui {
class disease;
}

class disease : public QWidget
{
    Q_OBJECT

public:
    explicit disease(QWidget *parent = nullptr);
    ~disease();\

public:
    void appendOneRow(QString name,QString dise,QString doctor,QString symptom,QString prescription,QString money,QString advice);

private slots:
    void on_pushButton_2_clicked();
    void read_data();

    void on_pushButton_clicked();

private:
    Ui::disease *ui;
    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    int sql_port;
    QHostAddress my_ip;
    int my_port;
};

#endif // DISEASE_H
