#ifndef HANDLEAPMENT_H
#define HANDLEAPMENT_H

#include <QWidget>

namespace Ui {
class handleApment;
}

class handleApment : public QWidget
{
    Q_OBJECT

public:
    explicit handleApment(QWidget *parent = nullptr);
    ~handleApment();
    QString patient_name;

private slots:
    void on_tijiaoBtn_clicked();

private:
    Ui::handleApment *ui;
};

#endif // HANDLEAPMENT_H
