#include "login.h"
#include "ui_login.h"
#include "signup.h"
#include "docmain.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QSqlDatabase>            //最后应该用不上
#include <QSqlQuery>               //最后应该用不上
#include <QSqlError>               //最后应该用不上
#include <QDebug>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}



void login::on_signup_btn_clicked()
{
    this->close();
    signup *s = new signup;
    s->show();
}

void login::on_logBtn_clicked()
{
    QString username =ui->userLineEdit->text().trimmed();
    QString password =ui->passLineEdit->text();
//下面的以后需要改成向数据库发送的内容（socket）
    QString select = QString("select * from user where username='%1' and password ='%2'")
            .arg(username).arg(password);
    QSqlQuery query(select);

    //if(query.next())
    if(1)
    {

        if(ui->radioButton->isChecked())
        {
        QMessageBox::information(NULL,"信息","登录成功");
        this->close();
        docMain *docM=new docMain;
        docM->show();
        }
        else if(ui->radioButton_2->isChecked())
        {
        QMessageBox::information(NULL,"信息","登录成功");
        this->close();
        MainWindow *w = new MainWindow;
        w->show();
        }
        else
            QMessageBox::warning(this,tr("警告"),tr("请选择你的身份"),QMessageBox::Yes);
    }
    else
    {

        QMessageBox::warning(this,tr("警告"),
                             tr("user name or password error"),QMessageBox::Yes);
        ui->userLineEdit->clear();
        ui->passLineEdit->clear();
        ui->userLineEdit->setFocus();

    }
}
