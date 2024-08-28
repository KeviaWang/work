#ifndef DRAWDIALOG_H
#define DRAWDIALOG_H

#include <QDialog>

namespace Ui {
class drawDialog;
}

class drawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit drawDialog(QWidget *parent = nullptr);
    ~drawDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::drawDialog *ui;
};

#endif // DRAWDIALOG_H
