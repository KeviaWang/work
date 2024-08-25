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

private slots:
    void on_tijiaoButton_clicked();

private:
    Ui::handleApment *ui;
};

#endif // HANDLEAPMENT_H
