#ifndef DOC_INFOMATION_H
#define DOC_INFOMATION_H

#include <QWidget>

namespace Ui {
class doc_infomation;
}

class doc_infomation : public QWidget
{
    Q_OBJECT

public:
    explicit doc_infomation(QWidget *parent = nullptr);
    ~doc_infomation();

private:
    Ui::doc_infomation *ui;
};

#endif // DOC_INFOMATION_H
