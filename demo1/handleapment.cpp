#include "handleapment.h"
#include "ui_handleapment.h"

handleApment::handleApment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::handleApment)
{
    ui->setupUi(this);
}

handleApment::~handleApment()
{
    delete ui;
}

void handleApment::on_tijiaoBtn_clicked()
{
    QString bingli = ui->bingliEdit->text();
    QString chufang = ui->chufangEdit->text();
    QString yizhu = ui->yizhuEdit->text();
    QString jiaofei = ui->jiaofeiEdit->text();


}
