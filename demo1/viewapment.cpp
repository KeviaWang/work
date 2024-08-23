#include "viewapment.h"
#include "ui_viewapment.h"

viewApMent::viewApMent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewApMent)
{
    ui->setupUi(this);
}

viewApMent::~viewApMent()
{
    delete ui;
}
