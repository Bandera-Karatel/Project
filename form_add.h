#ifndef FORM_CREATE_H
#define FORM_CREATE_H
#include "roster.h"
#include <QWidget>

namespace Ui {
class Form_Add;
}

class Form_Add : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Add(QWidget *parent = 0);
    ~Form_Add();

private:
    Ui::Form_Add *ui;


private slots:
   void on_pushButton_2_clicked();

   void on_pushButton_clicked();

signals:
   void Hide_Add();
   void Add(Roster);
};

#endif // FORM_CREATE_H
