/*#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "platform.h"
#include "disease.h"
#include "doc_information.h"
#include "per_information.h"
#include "healthassessment.h"
#include "mainwidget.h"
#include "chatworker.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    disease *dis = new disease;
    dis->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    doc_information *doc = new doc_information;
    doc->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    per_information *per = new per_information;
    per->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    //platform *plat = new platform;
    //plat->show();
    MainWidget *mwid = new MainWidget;
    mwid->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    healthassessment *heal = new healthassessment;
    heal->show();
}*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "platform.h"
#include "disease.h"
#include "doc_information.h"
#include "per_information.h"
#include "healthassessment.h"
#include "mainwidget.h"
#include "chatworker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    disease *dis = new disease;
    dis->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    doc_information *doc = new doc_information;
    doc->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    per_information *per = new per_information;
    per->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    // 创建并显示 MainWidget 窗口
    MainWidget *mwid = new MainWidget;
    mwid->show();
    QMetaObject::invokeMethod(mwid, "on_ConnectButton_Clicked", Qt::QueuedConnection);

}

void MainWindow::on_pushButton_9_clicked()
{
    healthassessment *heal = new healthassessment;
    heal->show();
}

