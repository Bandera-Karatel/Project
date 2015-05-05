#include "processingmanager.h"

ProcessingManager::ProcessingManager(QObject *parent) :
    QObject(parent)
{
    poolSize=2;
}

void ProcessingManager::ProcesRoster(Roster * roster)
{
    queue.enqueue(roster);
    updatePool();
}

void ProcessingManager::RemoveRoster()
{
    Thread *thread = (Thread *)sender();
    pool.removeOne(thread);
    thread->deleteLater();
}

void ProcessingManager::updatePool()
{
    if(pool.size()>=poolSize){
        return;
    }
    if(queue.isEmpty()){
        return;
    }
    Roster *roster = queue.dequeue();
    Thread *thread = new Thread(roster);
    connect(thread,SIGNAL(finished()),this,SLOT(RemoveRoster()));
    pool.append(thread);
    thread->start();
    updatePool();
}
