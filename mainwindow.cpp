#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new ListModel();
    ui->tableView->setModel(model);

    processingmanager = new ProcessingManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    emit Shov_Add();
}

void MainWindow::on_pushButton_4_clicked()
{
    emit Shov_Step();
}

void MainWindow::Slot(Roster *Data)
{
    model->listAdd(Data);
    Data->TimerStart();
    connect(Data,SIGNAL(timeout(Roster*)),processingmanager,SLOT(ProcesRoster(Roster*)));
}


void MainWindow::on_pushButton_3_clicked()
{

     QModelIndex Index = ui->tableView->selectionModel()->currentIndex();
     if(Index.isValid())
     model->listRemove(Index);
}
