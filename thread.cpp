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
    if(compareLastModified()){
        emit finished();
        return;
    }
    donloadFile();
}

QString Thread::getLastModified(QUrl url)
{
        QNetworkRequest request(url);
        QNetworkReply *reply = manager.head(request);
        return reply->header(QNetworkRequest::LastModifiedHeader).toString();

}

bool Thread::compareLastModified()
{
    QString lastmodified = this->getLastModified(this->roster->getU());
    if(lastmodified == this->roster->getL()){
        this->roster->setL(lastmodified);
        return true;
    }
}

void Thread::donloadFile()
{
    if(compareLastModified()){
    emit finished();
    return;
    }
    QString saveFilePath = QString("C:/" + this->roster->getN());
    QNetworkRequest request(this->roster->getU());
    QNetworkReply *reply = manager.get(request);
    file = new QFile;
    file->setFileName(saveFilePath);
    file->open(QIODevice::WriteOnly);
    file->write(reply->readAll());
    file->close();
}

void Thread::isFinished()
{
    emit finished();
}
