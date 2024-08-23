#ifndef PLATFORM_H
#define PLATFORM_H

#include <QWidget>

namespace Ui {
class platform;
}

class platform : public QWidget
{
    Q_OBJECT

public:
    explicit platform(QWidget *parent = nullptr);
    ~platform();

private:
    Ui::platform *ui;
};

#endif // PLATFORM_H
