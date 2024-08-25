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

    ui->tableWidget->setColumnCount(7);   //修改列数
    ui->tableWidget->setRowCount(1);

    QStringList hlist;
    hlist << "name";
    hlist << "disease";
    hlist << "doctor";
    hlist << "symptom";
    hlist << "prescription";
    hlist << "advice";
    hlist << "money";


    ui->tableWidget->setRowHeight(0, 200);

    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setColumnWidth(6,300);
}

disease::~disease()
{
    delete ui;
}

void disease::appendOneRow(QString name,QString dise,QString doctor,QString symptom,QString prescription,QString money,QString advice)
{


   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * diseItem=new QTableWidgetItem(dise);
   QTableWidgetItem * doctorItem=new QTableWidgetItem(doctor);
   QTableWidgetItem * symptomItem=new QTableWidgetItem(symptom);
   QTableWidgetItem * prescriptionItem=new QTableWidgetItem(prescription);
   QTableWidgetItem * moneyItem = new QTableWidgetItem(money);
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
   ui->tableWidget->setItem(0,5,moneyItem);
   ui->tableWidget->setItem(0,6,adviceItem);


}

void disease::on_pushButton_2_clicked()
{
    // 操作信号：0：医生端注册 1：患者端注册 2：医生端登录 3：患者端登录 4：医生端编辑个人信息 5：患者端编辑个人信息
    //          6：查看挂号信息 7：编写病例 编写处方和缴费 8：查看病例、查看处方和缴费 9：查看医生信息

    //发送信息，要求数据库传送过来表中所需的数据
    appendOneRow("name","disease","doctor","symbol","prescription","money","多读书多看报，少吃零食多睡觉");//在这里输入传过来的信息
}
