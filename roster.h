#ifndef Q_LIST_H
#define Q_LIST_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QDateTime>

class Roster : public QObject
{
    Q_OBJECT
private:
   QString Url;
   QString Name;
   QString Adress;
   int Time;
   QTimer *timer;
   QString LastModified;
   QString Path;


public:
   explicit Roster();

    void setU(QString);
    void setN(QString);
    void setA(QString);
    void setT(int);
    void setL(QString);
    QString getU();
    QString getN();
    QString getA();
    int getT();
    QString getL();

public slots:
    void TimerStart();

private slots:
    void TimerTimeout();

signals:
    void timeout(Roster*);
};

#endif // Q_LIST_H
