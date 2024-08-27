#include "healthassessment.h"
#include "ui_healthassessment.h"
#include <QMessageBox>

healthassessment::healthassessment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::healthassessment)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(4);

    QStringList hlist;
    hlist << "BMI";
    hlist << "血压";
    hlist << "血脂";
    hlist << "血压";

    ui->tableWidget->setHorizontalHeaderLabels(hlist);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充列的宽度000000
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

healthassessment::~healthassessment()
{
    delete ui;
}

void healthassessment::on_pushButton_clicked()
{
    QString height = ui->lineEdit->text();
    float  hei = height.toFloat();

    QString weight = ui->lineEdit_2->text();
    float  wei = weight.toFloat();

    QString contract = ui->lineEdit_3->text();
    float  con = contract.toFloat();

    QString diastole= ui->lineEdit_6->text();
    float  dia = diastole.toFloat();

    QString tcc= ui->lineEdit_4->text();
    float  tc = tcc.toFloat();

    QString sugar= ui->lineEdit_5->text();
    float  su = sugar.toFloat();

    QString one;
    float BMI = wei/(hei*hei);
    if(BMI<18.5)
        one = "偏瘦";
    else if(BMI>24)
        one = "偏胖";
    else
        one = "正常";
    QString two;
    if(con<90&&dia<60)
        two = "低血压";
    else if(con>140&&dia>90)
        two = "高血压";
    else
        two = "正常";
    QString three;
    if(tc<5.2)
        three = "正常";
    else
        three = "异常";
    QString four;
    if(su>6.1)
        four = "异常";
    else
        four = "正常";


    QTableWidgetItem * nameItem=new QTableWidgetItem(one);
    QTableWidgetItem * genderItem=new QTableWidgetItem(two);
    QTableWidgetItem * roomItem=new QTableWidgetItem(three);
    QTableWidgetItem * contactItem=new QTableWidgetItem(four);


    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);//居中
    roomItem->setTextAlignment(Qt::AlignCenter);
    contactItem->setTextAlignment(Qt::AlignCenter);



    ui->tableWidget->setItem(0,0,nameItem);
    ui->tableWidget->setItem(0,1,genderItem);
    ui->tableWidget->setItem(0,2,roomItem);
    ui->tableWidget->setItem(0,3,contactItem);




}

void healthassessment::on_pushButton_2_clicked()
{
    this->close();
    this->~healthassessment();
}
