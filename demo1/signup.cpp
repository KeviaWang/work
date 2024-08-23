#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include<QMessageBox>
#include <QSqlDatabase>  //最后应该用不上
#include <QSqlQuery>    //最后应该用不上
#include <QSqlError>  //最后应该用不上
#include <QDebug>
signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_2_clicked()
{
    QString username = ui->username->text().trimmed();
    QString password = ui->password->text();
    QString confirmword = ui->confirmword->text();

    if(password==confirmword)  //same
    {

        //改为向数据端发送socket,现在没数据库，肯定插入失败
        QString ins=QString("insert into user(username,password) values('%1','%2');")
                .arg(username).arg(password);
        QSqlQuery query;

        //如果可以收到插入成功的信号，可保留下面的代码
        if(!query.exec(ins))
        {
            qDebug()<<"insert into error";
            QMessageBox::information(this,"确定","插入失败！");
        }
        else
        {
            qDebug()<<"insert into sucess";
            QMessageBox::information(this,"确定","插入成功！");
        }
    }
    else
    {
        QMessageBox::information(this,"确定","密码不一致");
    }
}

void signup::on_pushButton_clicked()
{
    login *log = new login;
    this->close();
    log->show();
}
