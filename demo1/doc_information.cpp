#include "doc_information.h"
#include "ui_doc_information.h"

doc_information::doc_information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_information)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);   //修改列数
    ui->tableWidget->setRowCount(1);

    QStringList hlist;
    hlist << "name";
    hlist << "dise";


    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充列的宽度

    appendOneRow("mina","hot");

}

doc_information::~doc_information()
{
    delete ui;
}
void doc_information::appendOneRow(QString name, QString dise)
{


   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * diseItem=new QTableWidgetItem(dise);

   nameItem->setTextAlignment(Qt::AlignCenter);
   diseItem->setTextAlignment(Qt::AlignCenter);//居中

   ui->tableWidget->setItem(0,0,nameItem);
   ui->tableWidget->setItem(0,1,diseItem);

}
