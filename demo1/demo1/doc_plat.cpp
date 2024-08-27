#include "doc_plat.h"
#include "ui_doc_plat.h"

doc_plat::doc_plat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_plat)
{
    ui->setupUi(this);
}

doc_plat::~doc_plat()
{
    delete ui;
}
