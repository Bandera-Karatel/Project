#ifndef Q_LIST_H
#define Q_LIST_H
#include <QString>

class Roster
{
private:
   QString Url;
   QString Name;
   QString Adress;
   int Time;


public:
    friend class  Form_Add;
    void setU(QString);
    void setN(QString);
    void setA(QString);
    void setT(int);
    QString getU();
    QString getN();
    QString getA();
    int getT();
    Roster();
};

#endif // Q_LIST_H
