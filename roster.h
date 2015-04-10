#ifndef Q_LIST_H
#define Q_LIST_H
#include <QString>
#include <QTimer>
class Roster
{
private:
   QString Url;
   QString Name;
   QString Adress;
   int Time;
   QTimer *timer;



public:
    void setU(QString);
    void setN(QString);
    void setA(QString);
    void setT(int);
    QString getU();
    QString getN();
    QString getA();
    int getT();
    Roster();
public slots:
    void TimerStart();
};

#endif // Q_LIST_H
