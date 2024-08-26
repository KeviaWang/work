#ifndef VIEWAPMENT_H
#define VIEWAPMENT_H
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
class viewApMent;
}

class viewApMent : public QWidget
{
    Q_OBJECT

public:
    explicit viewApMent(QWidget *parent = nullptr);
    ~viewApMent();
public:
    void appendOneRow(int row,QString name,QString gender,QString birth,QString height,QString weight,QString disease,QString family_history);

private slots:
    void on_pushButton_2_clicked();

    void on_goutong_clicked();

    void on_chufangyizhu_clicked();
    void read_data();

    void on_pushButton_clicked();

private:
    Ui::viewApMent *ui;
    QUdpSocket* m_socket;
    QHostAddress sql_ip;
    int sql_port;
    QHostAddress my_ip;
    int my_port;
};

#endif // VIEWAPMENT_H
