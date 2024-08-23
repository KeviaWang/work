#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "platform.h"
#include "disease.h"
#include "doc_information.h"
#include "per_information.h"
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
    platform *plat = new platform;
    plat->show();
}
