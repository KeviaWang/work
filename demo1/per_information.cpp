#include "per_information.h"
#include "ui_per_information.h"

per_information::per_information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::per_information)
{
    ui->setupUi(this);
}

per_information::~per_information()
{
    delete ui;
}

void per_information::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit->text().trimmed();
    QString gender = ui->lineEdit_2->text().trimmed();
    QString birth = ui->lineEdit_3->text().trimmed();
    QString height = ui->lineEdit_4->text().trimmed();
    QString weight = ui->lineEdit_5->text().trimmed();
    QString contact = ui->lineEdit_6->text().trimmed();
    QString home = ui->lineEdit_7->text().trimmed();
    QString ID = ui->lineEdit_8->text().trimmed();
    QString disease = ui->lineEdit_9->text().trimmed();
    QString family_history = ui->lineEdit_10->text().trimmed();
    QString medicine_use = ui->lineEdit_11->text().trimmed();
    QString insurance = ui->lineEdit_12->text().trimmed();
    QString emergency = ui->lineEdit_13->text().trimmed();

}
