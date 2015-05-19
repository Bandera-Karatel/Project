#include "mainwindow.h"
#include <QApplication>
#include <QNetworkProxy>
#include "form_step.h"
#include "form_add.h"
#include "processingmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Form_Add f;
    Form_Step f2;
    w.show();
    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("proxy.cic");
    proxy.setPort(3128);
    QNetworkProxy::setApplicationProxy(proxy);
    QObject::connect(&w,SIGNAL(Shov_Add()),&f,SLOT(show()));
    QObject::connect(&f,SIGNAL(Hide_Add()),&f,SLOT(hide()));
    QObject::connect(&w,SIGNAL(Shov_Step()),&f2,SLOT(show()));
    QObject::connect(&f,SIGNAL(Add(Roster*)),&w,SLOT(Slot(Roster*)));
    QObject::connect(&f2,SIGNAL(Hide_Step()),&f2,SLOT(hide()));
    QObject::connect(&f2,SIGNAL(Hide_Step_Save(int)),w.processingmanager,SLOT(poolSizeAdd(int)));
    return a.exec();
}
