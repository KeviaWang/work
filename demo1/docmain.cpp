#include "docmain.h"
#include "ui_docmain.h"
#include "viewapment.h"
#include "doc_edit.h"
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

void docMain::on_gerenxinxi_clicked()
{
    doc_edit * edit = new doc_edit; 
    edit->show();

}

void docMain::on_bingqingchuli_clicked()
{
    viewApMent *view = new viewApMent;
    view->show();

}


void docMain::on_shujutu_clicked()
{
    drawDialog * draw=new drawDialog;
    draw->show();

}
