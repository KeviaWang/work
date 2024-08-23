#include "platform.h"
#include "ui_platform.h"

platform::platform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::platform)
{
    ui->setupUi(this);
}

platform::~platform()
{
    delete ui;
}
