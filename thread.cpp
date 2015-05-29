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

void Thread::run1()
{
    manager = new QNetworkAccessManager();
    QNetworkRequest request(roster->getU());
    reply = manager->head(request);
    connect(reply,SIGNAL(finished()),this,SLOT(donloadFile()));
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
    QString saveFilePath = QString("C:/Users/lab124/Desktop/1.html");
    QNetworkRequest request(this->roster->getU());
    QNetworkReply *reply;
    reply = manager->get(request);
    file = new QFile;
    file->setFileName(saveFilePath);
    file->open(QIODevice::WriteOnly);
    bytesSaved = 0;
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(downloadProgress(qint64,qint64)));
    connect(reply,SIGNAL(finished()),this,SLOT(isFinished()));
}

void Thread::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qint64 byteToSave = bytesReceived - bytesSaved;
    if (byteToSave > 0) {
       // QByteArray data = reply->read(byteToSave);
        file->write(reply->readAll());
        bytesSaved += byteToSave;
    }
}

void Thread::isFinished()
{
    file->close();
   // emit finish();
}
