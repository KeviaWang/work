#include "docmain.h"
#include "ui_docmain.h"
#include "handleapment.h"
#include "viewapment.h"
#include "doc_edit.h"
#include "doc_plat.h"
docMain::docMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::docMain)
{
    ui->setupUi(this);
}

docMain::~docMain()
{
    delete ui;
}

void docMain::on_pushButton_2_clicked()
{
    doc_edit * edit = new doc_edit;
    edit->show();
}

void docMain::on_pushButton_3_clicked()
{
    viewApMent *view = new viewApMent;
    view->show();
}

void docMain::on_pushButton_4_clicked()
{
    handleApment *hand = new handleApment;
    hand->show();
}

void docMain::on_pushButton_5_clicked()
{
    doc_plat *plat = new doc_plat;
    plat->show();
}
