#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QUrl>
#include <QNetworkAccessManager>
class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0);
    void run();
    void getLastModified(QUrl);
signals:

public slots:

};

#endif // THREAD_H
