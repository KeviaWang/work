#ifndef DOCMAIN_H
#define DOCMAIN_H

#include <QWidget>
#include <QNetworkInterface>
#include "drawdialog.h"
namespace Ui {
class docMain;
}

class docMain : public QWidget
{
    Q_OBJECT

public:
    explicit docMain(QWidget *parent = nullptr);
    ~docMain();

private slots:
    void on_gerenxinxi_clicked();

    void on_bingqingchuli_clicked();


    void on_shujutu_clicked();

private:
    Ui::docMain *ui;
};

#endif // DOCMAIN_H
