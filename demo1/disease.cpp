#include "disease.h"
#include "ui_disease.h"
#include <QTextEdit>
#include <QApplication>
#include <QTableWidget>
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


    ui->tableWidget->setRowHeight(0, 200);

    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setColumnWidth(5,300);
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


   //QTextEdit *textEdit = new QTextEdit();
   //textEdit->setText(advice);
   //textEdit->setWordWrapMode(QTextOption::WordWrap); // Ensure text wraps
   //ui->tableWidget->setCellWidget(0, 5, textEdit);





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
    appendOneRow("lily","hot","a","b","c","多读书多看报，少吃零食多睡觉uioashdfuoiewdfbjkasdbiadg");//在这里输入传过来的信息
}
