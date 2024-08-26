#include "login.h"
#include <QApplication>
#include "mainwindow.h"
#include "signup.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login dlg;
 /*   if(dlg.exec()==QDialog::Accepted)
    {
    si.show();
    return a.exec();
    }
    else
     return 0;
 */
    dlg.show();
    return a.exec();
}
