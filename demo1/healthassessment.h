#ifndef HEALTHASSESSMENT_H
#define HEALTHASSESSMENT_H

#include <QWidget>

namespace Ui {
class healthassessment;
}

class healthassessment : public QWidget
{
    Q_OBJECT

public:
    explicit healthassessment(QWidget *parent = nullptr);
    ~healthassessment();

private slots:
    void on_pushButton_clicked();

private:
    Ui::healthassessment *ui;
};

#endif // HEALTHASSESSMENT_H
