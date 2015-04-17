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
        QNetworkRequest request(url);
        QNetworkReply *reply = manager.head(request);
        reply->header(QNetworkRequest::LastModifiedHeader).toString();

}
