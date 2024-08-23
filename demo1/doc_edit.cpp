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
