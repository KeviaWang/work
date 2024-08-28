#include "drawdialog.h"
#include "ui_drawdialog.h"



#include <QApplication>
#include <QMainWindow>
#include <QChartView>
#include <QScatterSeries>
#include <QValueAxis>
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QDebug>

using namespace QtCharts;


drawDialog::drawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drawDialog)
{
    ui->setupUi(this);
}

drawDialog::~drawDialog()
{
    delete ui;
}

void drawDialog::on_pushButton_clicked()
{
    QMainWindow *window=new QMainWindow;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("drug.db");

    if (!db.open())
    {
            qDebug() << "Error: Unable to open database." << db.lastError().text();

    }


        QSqlQuery query(db);
        QString drugname = ui->lineEdit->text();
        QString jjj=QString("select count(*)  FROM DRUG WHERE Drug = '%1' AND Sex = 'M' ").arg(drugname);
        QString kkk=QString("select count(*)  FROM DRUG WHERE Drug = '%1' AND Sex = 'F' ").arg(drugname);

        if (!query.exec(jjj))
        {
                qDebug() << "Error: Failed to execute query." << query.lastError().text();

        }

        int count=0;
        if (query.next())
        {
                count = query.value(0).toInt(); // 获取计数结果并转换为整数
                qDebug() << "Count of males:" << count;
        }
        else
        {
                qDebug() << "No results found.";
         }


        QSqlQuery buery(db);
        int otherCount = 0;
        if (!buery.exec(kkk))
        {
                qDebug() << "Error: Failed to execute query." << buery.lastError().text();

        }
        if (buery.next())
        {
                otherCount = buery.value(0).toInt(); // 获取计数结果并转换为整数
                qDebug() << "Count of males:" << otherCount;
        }
        else
        {
                qDebug() << "No results found.";
         }


        QPieSeries *series = new QPieSeries();
        QString title_1 = QString("M(%1)=%2").arg(drugname).arg(count);
        QString title_2 = QString("F(%1)=%2").arg(drugname).arg(otherCount);
        series->append(title_1, count);
        series->append(title_2, otherCount);


        QChart *chart = new QChart();
        chart->addSeries(series);
        QString title_3 = QString("Gender Radio for %1").arg(drugname);
        chart->setTitle(title_3);
        chart->legend()->setAlignment(Qt::AlignBottom);


        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        window->setCentralWidget(chartView);
        window->resize(800, 600);
        window->show();


}
