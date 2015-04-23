#include "thread.h"

Thread::Thread(QObject *parent) :
    QThread(parent)
{
}

Thread::Thread(Roster * roster,QObject *parent) :
    QThread(parent)
{
    this->roster = roster;
}

void Thread::run()
{
    //if(compareLastModified)emit finisfed return
    //donloadfile
}

QString Thread::getLastModified(QUrl url)
{
        QNetworkRequest request(url);
        QNetworkReply *reply = manager.head(request);
        return reply->header(QNetworkRequest::LastModifiedHeader).toString();

}
