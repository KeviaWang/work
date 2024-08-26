#ifndef DOC_EDIT_H
#define DOC_EDIT_H

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
class doc_edit;
}

class doc_edit : public QWidget
{
    Q_OBJECT

public:
    explicit doc_edit(QWidget *parent = nullptr);
    ~doc_edit();


private slots:
    void on_pushButton_2_clicked();
    void recvdata();

    void on_pushButton_clicked();

private:
    Ui::doc_edit *ui;
    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    int sql_port;
    QHostAddress my_ip;
    int my_port;

};

#endif // DOC_EDIT_H
