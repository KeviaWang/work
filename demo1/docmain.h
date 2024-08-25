#ifndef DOCMAIN_H
#define DOCMAIN_H

#include <QWidget>

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


private:
    Ui::docMain *ui;
};

#endif // DOCMAIN_H
