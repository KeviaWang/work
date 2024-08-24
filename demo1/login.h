#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDialog>
#include<QWidget>
#include<QUdpSocket>
#include<QMessageBox>

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

private:
    Ui::login *ui;
    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    quint16 sql_port;
    QHostAddress my_ip;
    quint16 my_port;
};

#endif // LOGIN_H
