#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include "roster.h"

class Thread : public QThread
{
    Q_OBJECT
    Roster *roster;
    QNetworkAccessManager *manager;
    QFile *file;
    QNetworkReply *reply;
    qint64 bytesSaved;
public:
    explicit Thread(QObject *parent = 0);
    explicit Thread(Roster *,QObject *parent = 0);
    void run1();
    bool compareLastModified();



signals:
    void finish();

public slots:
    void lastModified();
protected slots:
    void isFinished();
    void donloadFile();
    void downloadProgress(qint64,qint64);

};

#endif // THREAD_H
