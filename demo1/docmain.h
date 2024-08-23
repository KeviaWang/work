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
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::docMain *ui;
};

#endif // DOCMAIN_H
