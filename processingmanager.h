#ifndef PROCESSINGMANAGER_H
#define PROCESSINGMANAGER_H

#include <QObject>
#include "thread.h"

class ProcessingManager : public QObject
{
    Q_OBJECT

    QList<Thread> turn;
public:
    explicit ProcessingManager(QObject *parent = 0);

signals:

public slots:

};

#endif // PROCESSINGMANAGER_H