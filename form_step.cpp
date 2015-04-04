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
