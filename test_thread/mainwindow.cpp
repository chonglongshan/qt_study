#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _lz_thread_worker(nullptr)
    , _lz_worker_action(new LzWorkerAction())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_thread_start_clicked()
{

//    _lz_thread_worker = new LzThread();
//    _lz_worker_action->moveToThread(_lz_thread_worker);
//    connect(_lz_thread_worker, &QThread::finished, _lz_worker_action, &LzWorkerAction::lzThreadFinished);
//    connect(_lz_thread_worker, &QThread::finished, _lz_worker_action, &QObject::deleteLater);
//    connect(_lz_thread_worker, &QThread::started, _lz_worker_action, &LzWorkerAction::lzThreadStarted);
    _lz_thread_worker->start();
}

void MainWindow::on_pushButton_thread_quit_clicked()
{
    qDebug() << QString::fromUtf8("1 isRunning = ") << _lz_thread_worker->isRunning();
    _lz_thread_worker->quit();
    qDebug() << QString::fromUtf8("quit");
    _lz_thread_worker->wait();
    qDebug() << _lz_thread_worker;
    qDebug() << QString::fromUtf8("2 isRunning = ") << _lz_thread_worker->isRunning();
//    //delete _lz_thread_worker;
//    _lz_thread_worker = nullptr;
//    qDebug() << _lz_thread_worker;
//    //qDebug() << QString::fromUtf8("3 isRunning = ") << _lz_thread_worker->isRunning(); // 异常错误
}

void MainWindow::on_pushButton_thread_object_construct_clicked()
{
    qDebug() << QString::fromUtf8("QThread::currentThread = ") << QThread::currentThread();

    _lz_thread_worker = new LzThread();

//    if( nullptr == _lz_worker_action->thread() ||
//            QThread::currentThread() == _lz_worker_action->thread() )
//    {
//        _lz_worker_action->moveToThread(_lz_thread_worker);
//    }

    _lz_worker_action->moveToThread(_lz_thread_worker);

    connect(_lz_thread_worker, &QThread::finished, _lz_worker_action, &LzWorkerAction::lzThreadFinished);
//    connect(_lz_thread_worker, &QThread::finished, _lz_worker_action, &QObject::deleteLater);
    connect(_lz_thread_worker, &QThread::started, _lz_worker_action, &LzWorkerAction::lzThreadStarted);
    connect(this, &MainWindow::lzSignalAction, _lz_worker_action, &LzWorkerAction::lzThreadRunning);
    connect(this, &MainWindow::lzSignalMoveToMainThread, _lz_worker_action, &LzWorkerAction::lzMoveToMainThread);
}

void MainWindow::on_pushButton_thread_action_clicked()
{
    emit lzSignalAction();
}

void MainWindow::on_pushButton_thread_object_delete_clicked()
{
    disconnect(_lz_thread_worker, &QThread::finished, _lz_worker_action, &LzWorkerAction::lzThreadFinished);
//    connect(_lz_thread_worker, &QThread::finished, _lz_worker_action, &QObject::deleteLater);
    disconnect(_lz_thread_worker, &QThread::started, _lz_worker_action, &LzWorkerAction::lzThreadStarted);
    disconnect(this, &MainWindow::lzSignalAction, _lz_worker_action, &LzWorkerAction::lzThreadRunning);
    //_lz_worker_action->moveToThread(QThread::currentThread()); // 类实体对象现在还归属于另一个 QThread
    //_lz_worker_action->moveToThread(nullptr);
    disconnect(this, &MainWindow::lzSignalMoveToMainThread, _lz_worker_action, &LzWorkerAction::lzMoveToMainThread);

    delete _lz_thread_worker;
    _lz_thread_worker = nullptr;
    qDebug() << _lz_thread_worker;

    qDebug() << _lz_worker_action->thread();

    //_lz_worker_action->moveToThread(QThread::currentThread()); // 类实体对象现在所归属的另一个 QThread 已经被销毁。（与是否置 nullptr 无所谓）
    // terminate 强制中断/关闭线程时，有可能未来得及执行 lzThreadFinished 内的 moveToThread 。
    //_lz_worker_action->moveToThread(QApplication::instance()->thread()); // 确保执行 moveToThread  // 循环情况下有异常。 terminate 使得线程肯定有资源没有测底释放完。
    //_lz_worker_action->moveToThread(QThread::currentThread()); // 确保执行 moveToThread // 还是最好在归属线程内 move

    qDebug() << _lz_worker_action->thread();

//    if( nullptr == _lz_worker_action->thread())
//    {
//        _lz_worker_action->moveToThread(nullptr);
//        //_lz_worker_action->moveToThread(QApplication::instance()->thread()); // 异常
//    }
}

void MainWindow::on_pushButton_thread_exit_clicked()
{
    qDebug() << QString::fromUtf8("isRunning = ") << _lz_thread_worker->isRunning();
    _lz_thread_worker->exit(); // 效果与 quit 相似
    qDebug() << QString::fromUtf8("exit");
    _lz_thread_worker->wait();
    qDebug() << _lz_thread_worker;
    qDebug() << QString::fromUtf8("isRunning = ") << _lz_thread_worker->isRunning();
}

void MainWindow::on_pushButton_thread_terminate_clicked()
{
    emit lzSignalMoveToMainThread();
    QThread::msleep(1000);

    qDebug() << QString::fromUtf8("isRunning = ") << _lz_thread_worker->isRunning();
    _lz_thread_worker->terminate(); // 实测可以强制中断/关闭线程 ，即使带 event loop 。
    qDebug() << QString::fromUtf8("terminate");
    _lz_thread_worker->wait();
    qDebug() << _lz_thread_worker;
    qDebug() << QString::fromUtf8("isRunning = ") << _lz_thread_worker->isRunning();
}
