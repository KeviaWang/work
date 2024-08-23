#include "disease.h"
#include "ui_disease.h"

disease::disease(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::disease)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);   //修改列数
    ui->tableWidget->setRowCount(1);

    QStringList hlist;
    hlist << "name";
    hlist << "dise";


    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充列的宽度

    appendOneRow("lily","hot");//在这里输入传过来的信息
}

disease::~disease()
{
    delete ui;
}
void disease::appendOneRow(QString name, QString dise)
{


   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * diseItem=new QTableWidgetItem(dise);

   nameItem->setTextAlignment(Qt::AlignCenter);
   diseItem->setTextAlignment(Qt::AlignCenter);//居中

   ui->tableWidget->setItem(0,0,nameItem);
   ui->tableWidget->setItem(0,1,diseItem);

}
