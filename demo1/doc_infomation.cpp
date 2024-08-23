#include "doc_infomation.h"
#include "ui_doc_infomation.h"

doc_infomation::doc_infomation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_infomation)
{
    ui->setupUi(this);
}

doc_infomation::~doc_infomation()
{
    delete ui;
}
