#include "thread.h"

Thread::Thread(QObject *parent) :
    QThread(parent)
{
}

void Thread::run()
{

}

void Thread::getLastModified(QUrl url)
{
        QNetworkRequest Reques(url);
        Reques.hea

}
