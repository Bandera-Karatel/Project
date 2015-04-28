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
    QNetworkAccessManager manager;
    QFile *file;
public:
    explicit Thread(QObject *parent = 0);
    explicit Thread(Roster *,QObject *parent = 0);
    void run();
    QString getLastModified(QUrl);
    bool compareLastModified();
    void donloadFile();

signals:
    void finisfed();

public slots:

};

#endif // THREAD_H
