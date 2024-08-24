#include "doc_information.h"
#include "ui_doc_information.h"

doc_information::doc_information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doc_information)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(7);   //修改列数
    ui->tableWidget->setRowCount(1);

    QStringList hlist;
    hlist << "姓名";
    hlist << "性别";
    hlist << "科室";
    hlist << "联系方式";
    hlist << "职位";
    hlist << "专业领域";
    hlist << "工作年限";

    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充列的宽度



}

doc_information::~doc_information()
{
    delete ui;
}
void doc_information::appendOneRow(QString name,QString gender,QString room,QString contact,QString positon,QString major,QString year)
{


   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * genderItem=new QTableWidgetItem(gender);
   QTableWidgetItem * roomItem=new QTableWidgetItem(room);
   QTableWidgetItem * contactItem=new QTableWidgetItem(contact);
   QTableWidgetItem * posionItem=new QTableWidgetItem(positon);
   QTableWidgetItem * majorItem=new QTableWidgetItem(major);
   QTableWidgetItem * yearItem=new QTableWidgetItem(year);

   nameItem->setTextAlignment(Qt::AlignCenter);
   genderItem->setTextAlignment(Qt::AlignCenter);//居中
   roomItem->setTextAlignment(Qt::AlignCenter);
   contactItem->setTextAlignment(Qt::AlignCenter);
   posionItem->setTextAlignment(Qt::AlignCenter);
   majorItem->setTextAlignment(Qt::AlignCenter);
   yearItem->setTextAlignment(Qt::AlignCenter);



   ui->tableWidget->setItem(0,0,nameItem);
   ui->tableWidget->setItem(0,1,genderItem);
   ui->tableWidget->setItem(0,2,roomItem);
   ui->tableWidget->setItem(0,3,contactItem);
   ui->tableWidget->setItem(0,4,posionItem);
   ui->tableWidget->setItem(0,5,majorItem);
   ui->tableWidget->setItem(0,6,yearItem);
}

void doc_information::on_pushButton_3_clicked()
{
    QString doc_name = ui->lineEdit->text();//将医生姓名和user姓名送到预约表
}

void doc_information::on_pushButton_2_clicked()
{
    //发送信息，要求数据库传送过来表中所需的数据
    appendOneRow("mina","hot","a","s","d","r","f");
}
