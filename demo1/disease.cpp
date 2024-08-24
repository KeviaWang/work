#include "disease.h"
#include "ui_disease.h"

disease::disease(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::disease)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(6);   //修改列数
    ui->tableWidget->setRowCount(1);

    QStringList hlist;
    hlist << "name";
    hlist << "disease";
    hlist << "doctor";
    hlist << "symptom";
    hlist << "prescription";
    hlist << "advice";

    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充列的宽度


}

disease::~disease()
{
    delete ui;
}

void disease::appendOneRow(QString name,QString dise,QString doctor,QString symptom,QString prescription,QString advice)
{


   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * diseItem=new QTableWidgetItem(dise);
   QTableWidgetItem * doctorItem=new QTableWidgetItem(doctor);
   QTableWidgetItem * symptomItem=new QTableWidgetItem(symptom);
   QTableWidgetItem * prescriptionItem=new QTableWidgetItem(prescription);
   QTableWidgetItem * adviceItem=new QTableWidgetItem(advice);

   nameItem->setTextAlignment(Qt::AlignCenter);
   diseItem->setTextAlignment(Qt::AlignCenter);//居中

   ui->tableWidget->setItem(0,0,nameItem);
   ui->tableWidget->setItem(0,1,diseItem);
   ui->tableWidget->setItem(0,2,doctorItem);
   ui->tableWidget->setItem(0,3,symptomItem);
   ui->tableWidget->setItem(0,4,prescriptionItem);
   ui->tableWidget->setItem(0,5,adviceItem);

}

void disease::on_pushButton_2_clicked()
{
    //发送信息，要求数据库传送过来表中所需的数据
    appendOneRow("lily","hot","a","b","c","d");//在这里输入传过来的信息
}
