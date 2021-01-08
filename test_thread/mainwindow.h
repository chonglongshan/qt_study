#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "lzworkeraction.h"
#include "lzthread.h"
#include "lzworkerthread.h"

#include <QMainWindow>
//#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void lzSignalAction();
    void lzSignalMoveToMainThread();

private slots:
//    void on_pushButton_thread_start_clicked();

//    void on_pushButton_thread_quit_clicked();

//    void on_pushButton_thread_object_construct_clicked();

//    void on_pushButton_thread_action_clicked();

//    void on_pushButton_thread_object_delete_clicked();

//    void on_pushButton_thread_exit_clicked();

//    void on_pushButton_thread_terminate_clicked();

    void on_pushButton_thread_object_construct_2_clicked();

    void on_pushButton_thread_start_2_clicked();

    void on_pushButton_thread_action_2_clicked();

    void on_pushButton_thread_quit_2_clicked();

    void on_pushButton_thread_exit_2_clicked();

    void on_pushButton_thread_terminate_2_clicked();

    void on_pushButton_thread_object_delete_2_clicked();

private:
    Ui::MainWindow *ui;

    //
    //QThread *_lz_thread_worker;
//    LzThread *_lz_thread_worker;
//    LzWorkerAction *_lz_worker_action;

    //
    LzWorkerThread *_lz_thread;
};
#endif // MAINWINDOW_H
