#ifndef PROCESSINGMANAGER_H
#define PROCESSINGMANAGER_H

#include <QObject>
#include <QQueue>
#include "roster.h"
#include "thread.h"

class ProcessingManager : public QObject
{
    Q_OBJECT

    QList<Thread *> pool;
    QQueue<Roster *> queue;
    int poolSize;
public:
    explicit ProcessingManager(QObject *parent = 0);

protected:
    void updatePool();

signals:

public slots:
    void ProcesRoster(Roster*);
    void RemoveRoster();
};

#endif // PROCESSINGMANAGER_H
