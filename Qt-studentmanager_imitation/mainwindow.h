#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include "studentform.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
//#include<manger.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginButton_clicked();
    void show2();
    // void open();
    void on_remitButton_clicked();

signals:
    void sendData(QString);
private:
    Ui::MainWindow *ui;
    studentForm *f;
    //    manger *m;
};
#endif // MAINWINDOW_H
