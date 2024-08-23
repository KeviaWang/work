#ifndef DOC_PLAT_H
#define DOC_PLAT_H

#include <QWidget>

namespace Ui {
class doc_plat;
}

class doc_plat : public QWidget
{
    Q_OBJECT

public:
    explicit doc_plat(QWidget *parent = nullptr);
    ~doc_plat();

private:
    Ui::doc_plat *ui;
};

#endif // DOC_PLAT_H
