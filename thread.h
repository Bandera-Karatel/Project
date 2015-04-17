#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "roster.h"

class Thread : public QThread
{
    Q_OBJECT
    QNetworkAccessManager manager;
public:
    explicit Thread(QObject *parent = 0);
    void run();
    void getLastModified(QUrl);
signals:

public slots:

};

#endif // THREAD_H
