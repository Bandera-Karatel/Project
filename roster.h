#ifndef Q_LIST_H
#define Q_LIST_H

#include <QObject>
#include <QString>
#include <QTimer>

class Roster : public QObject
{
    Q_OBJECT
private:
   QString Url;
   QString Name;
   QString Adress;
   int Time;
   QTimer *timer;



public:
   explicit Roster();

    void setU(QString);
    void setN(QString);
    void setA(QString);
    void setT(int);
    QString getU();
    QString getN();
    QString getA();
    int getT();

public slots:
    void TimerStart();

private slots:
    void TimerTimeout();

signals:
    void timeout();
};

#endif // Q_LIST_H
