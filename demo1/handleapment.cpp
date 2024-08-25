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
