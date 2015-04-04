#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "listmodel.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ListModel *model;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void Slot(Roster);




    void on_pushButton_3_clicked();

signals:
    void Shov_Add();
    void Shov_Step();
};

#endif // MAINWINDOW_H
