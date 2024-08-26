#ifndef GUAHAO_H
#define GUAHAO_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
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

QT_BEGIN_NAMESPACE
namespace Ui { class Guahao; }  // 这只是一个前向声明
QT_END_NAMESPACE

class Guahao : public QMainWindow
{
    Q_OBJECT

public:
    Guahao(QWidget *parent = nullptr);
    ~Guahao();

    QString doctor_name;

private slots:
    void onDateChanged();
    void on_pushButton_clicked();
    void read_data();

private:
    void populateComboBox();


    Ui::Guahao *ui;
    QSqlDatabase db;

    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    int sql_port;
    QHostAddress my_ip;
    int my_port;
};

#endif // GUAHAO_H
