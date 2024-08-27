#ifndef DOC_INFORMATION_H
#define DOC_INFORMATION_H
#include "guahao.h"

#include <QWidget>
#include <QNetworkInterface>
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
class doc_information;
}

class doc_information : public QWidget
{
    Q_OBJECT

public:
    explicit doc_information(QWidget *parent = nullptr);
    ~doc_information();
public:
void appendOneRow(int row,QString name,QString gender,QString room,QString contact,QString positon,QString major,QString year);

private slots:
void on_pushButton_3_clicked();

void on_pushButton_2_clicked();
void read_data();


void on_pushButton_clicked();

private:
    Ui::doc_information *ui;
    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    int sql_port;
    QHostAddress my_ip;
    int my_port;
};

#endif // DOC_INFORMATION_H
