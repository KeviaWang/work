#include "doc_edit.h"
#include "ui_doc_edit.h"

doc_edit::doc_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_edit)
{
    ui->setupUi(this);
}

doc_edit::~doc_edit()
{
    delete ui;
}

void doc_edit::on_pushButton_2_clicked()
{
    QString name =ui->nameEdit->text().trimmed();
    QString gender =ui->genderEdit->text().trimmed();
    QString room =ui->roomEdit->text().trimmed();
    QString contact =ui->contactEdit->text().trimmed();
    QString position =ui->positionEdit->text().trimmed();
    QString major =ui->majorEdit->text().trimmed();
    QString year =ui->yearEdit->text().trimmed();//要送到表里的数据

}
