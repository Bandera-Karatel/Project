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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Form_Step *ui;

signals:
    void Hide_Step();
    void Hide_Step_Save(int);
};

#endif // FORM_STEP_H
