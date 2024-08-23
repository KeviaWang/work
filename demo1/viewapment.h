#ifndef VIEWAPMENT_H
#define VIEWAPMENT_H

#include <QWidget>

namespace Ui {
class viewApMent;
}

class viewApMent : public QWidget
{
    Q_OBJECT

public:
    explicit viewApMent(QWidget *parent = nullptr);
    ~viewApMent();

private:
    Ui::viewApMent *ui;
};

#endif // VIEWAPMENT_H
