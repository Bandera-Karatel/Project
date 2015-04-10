#include "mainwindow.h"
#include <QApplication>
#include "form_step.h"
#include "form_add.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Form_Add f;
    Form_Step f2;
    w.show();
    QObject::connect(&w,SIGNAL(Shov_Add()),&f,SLOT(show()));
    QObject::connect(&f,SIGNAL(Hide_Add()),&f,SLOT(hide()));
    QObject::connect(&w,SIGNAL(Shov_Step()),&f2,SLOT(show()));
    QObject::connect(&f,SIGNAL(Add(Roster*)),&w,SLOT(Slot(Roster*)));
    return a.exec();
}
