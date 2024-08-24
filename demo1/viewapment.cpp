#include "viewapment.h"
#include "ui_viewapment.h"

viewApMent::viewApMent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewApMent)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(1);

    QStringList hlist;
    hlist << "name";
    hlist << "gender";
    hlist << "birth";
    hlist << "height";
    hlist << "weight";
    hlist << "disease";
    hlist << "famalily_history";

    ui->tableWidget->setHorizontalHeaderLabels(hlist);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //填充列的宽度
}

void viewApMent::appendOneRow(QString name,QString gender,QString birth,QString height,QString weight,QString disease,QString family_history)
{


   QTableWidgetItem * nameItem=new QTableWidgetItem(name);
   QTableWidgetItem * genderItem=new QTableWidgetItem(gender);
   QTableWidgetItem * birthItem=new QTableWidgetItem(birth);
   QTableWidgetItem * heightItem=new QTableWidgetItem(height);
   QTableWidgetItem * weightItem=new QTableWidgetItem(weight);
   QTableWidgetItem * diseaseItem=new QTableWidgetItem(disease);
   QTableWidgetItem * family_historyItem = new QTableWidgetItem(family_history);

   nameItem->setTextAlignment(Qt::AlignCenter);
   genderItem->setTextAlignment(Qt::AlignCenter);//居中
   birthItem->setTextAlignment(Qt::AlignCenter);
   heightItem->setTextAlignment(Qt::AlignCenter);
   weightItem->setTextAlignment(Qt::AlignCenter);
   diseaseItem->setTextAlignment(Qt::AlignCenter);
   family_historyItem->setTextAlignment(Qt::AlignCenter);

   ui->tableWidget->setItem(0,0,nameItem);
   ui->tableWidget->setItem(0,1,genderItem);
   ui->tableWidget->setItem(0,2,birthItem);
   ui->tableWidget->setItem(0,3,heightItem);
   ui->tableWidget->setItem(0,4,weightItem);
   ui->tableWidget->setItem(0,5,diseaseItem);
   ui->tableWidget->setItem(0,6,family_historyItem);

}



viewApMent::~viewApMent()
{
    delete ui;
}

void viewApMent::on_pushButton_2_clicked()
{


    appendOneRow("a","s","d","r","w","x","z");
}
