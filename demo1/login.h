#ifndef LOGIN_H
#define LOGIN_H

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

extern QString MainUser;

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_signup_btn_clicked();

    void on_logBtn_clicked();
    void read_data();

private:
    Ui::login *ui;
    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    int sql_port;
    QHostAddress my_ip;
    int my_port;

};

#endif // LOGIN_H
