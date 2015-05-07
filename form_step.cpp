#include "form_step.h"
#include "ui_form_step.h"

Form_Step::Form_Step(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Step)
{
    ui->setupUi(this);
}

Form_Step::~Form_Step()
{
    delete ui;
}

void Form_Step::on_pushButton_clicked()
{

    int poolSize = ui->spinBox->value();
    emit Hide_Step_Save(poolSize);
    emit Hide_Step();
}

void Form_Step::on_pushButton_2_clicked()
{
    emit Hide_Step();

}
