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
        emit finish();
        return;
    }
    donloadFile();
}

QString Thread::getLastModified(QUrl url)
{
        QNetworkRequest request(url);
        reply = manager.head(request);
        connect(reply,SIGNAL(finish()),this,SLOT(lastModified()));
}

void Thread::lastModified()
{
    if(compareLastModified()){
    emit finish();
    return;
    }
    this->donloadFile();
}

bool Thread::compareLastModified()
{

    QString lastmodified = reply->header(QNetworkRequest::LastModifiedHeader).toString();
    if(lastmodified == this->roster->getL()){
        return true;
    }
     this->roster->setL(lastmodified);
    return false;
}

void Thread::donloadFile()
{
    QString saveFilePath = QString(this->roster->getA() + QString("/") + this->roster->getN());
    QNetworkRequest request(this->roster->getU());
    reply = manager.get(request);
    file = new QFile;
    file->setFileName(saveFilePath);
    file->open(QIODevice::WriteOnly);
    bytesSaved = 0;
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(downloadProgress(qint64,qint64)));
    connect(reply,SIGNAL(finish()),this,SLOT(isFinished()));
}

void Thread::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qint64 byteToSave = bytesReceived - bytesSaved;
    if (byteToSave > 0) {
        file->write(reply->read(byteToSave));
        bytesSaved += byteToSave;
    }
}

void Thread::isFinished()
{
    file->close();
    emit finish();
}
