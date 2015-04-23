#include "roster.h"
#include "form_add.h"
Roster::Roster() : QObject()
{
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerTimeout()));
}

void Roster::setU(QString url)
{
    this->Url = url;
}

void Roster::setN(QString name)
{
    this->Name = name;
}

void Roster::setA(QString adress)
{
    this->Adress = adress;
}

void Roster::setT(int time)
{
    this->Time = time;
}

QString Roster::getU()
{
    return this->Url;
}

QString Roster::getN()
{
    return this->Name;
}

QString Roster::getA()
{
    return this->Adress;
}

int Roster::getT()
{
    return this->Time;
}

void Roster::TimerStart()
{
    this->timer->start(this->Time*60000);
}

void Roster::TimerTimeout()
{
    emit timeout(this);
}
