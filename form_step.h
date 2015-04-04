#ifndef FORM_STEP_H
#define FORM_STEP_H

#include <QWidget>

namespace Ui {
class Form_Step;
}

class Form_Step : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Step(QWidget *parent = 0);
    ~Form_Step();

private:
    Ui::Form_Step *ui;
};

#endif // FORM_STEP_H
