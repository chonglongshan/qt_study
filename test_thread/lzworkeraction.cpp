#include "lzworkeraction.h"

#include <QDebug>
#include <QApplication>
#include <QThread>

LzWorkerAction::LzWorkerAction(QObject *parent) : QObject(parent)
{

}

LzWorkerAction::~LzWorkerAction()
{
    qDebug() << QString::fromUtf8("~LzWorkerAction");
}

void LzWorkerAction::lzThreadStarted()
{
    qDebug() << QString::fromUtf8("lzThreadStarted");

    //qDebug() << QString::fromUtf8("run ......");

    qDebug() << QString::fromUtf8("QThread::currentThread = ") << QThread::currentThread();
}

void LzWorkerAction::lzThreadFinished()
{
    qDebug() << QString::fromUtf8("lzThreadFinished");

    //moveToThread(QApplication::instance()->thread()); // 类实体对象所归属的 QThread 内可以随意 move
    // 外部有 _lz_worker_action->moveToThread(QApplication::instance()->thread()); // 确保执行 moveToThread
    // 在 delete thread 后进行 move 。则此处可省略 move 。
}

void LzWorkerAction::lzThreadRunning()
{
//    qDebug() << QString::fromUtf8("run ......");

    // 死循环 （占用）
    unsigned int n = 0xFFFFFFFF; // 0xFFFFFFFFFFFFFFFF
    do
    {
        qDebug() << QString::fromUtf8("run ......");
        QThread::msleep(1000/* * 3*/);
    } while(--n);
}

void LzWorkerAction::lzMoveToMainThread()
{
    // 还是最好在归属线程内 move
    moveToThread(QApplication::instance()->thread()); // 死循环导致无法执行到信号触发的该函数。 没执行就已经 terminate 。
    qDebug() << QString::fromUtf8("lzMoveToMainThread");

    // terminate 的场景是极难再恢复原样。建议此种情况下，重新运行程序。
}
