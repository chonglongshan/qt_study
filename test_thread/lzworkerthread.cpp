#include "lzworkerthread.h"

#include <QDebug>

LzWorkerThread::LzWorkerThread(QObject *parent) : QThread(parent)
{
    qDebug() << QString::fromUtf8("LzWorkerThread::LzWorkerThread");
}

LzWorkerThread::~LzWorkerThread()
{
    qDebug() << QString::fromUtf8("LzWorkerThread::~LzWorkerThread");
}

void LzWorkerThread::run()
{
    QString result;
    /* ... here is the expensive or blocking operation ... */
    qDebug() << QString::fromUtf8("LzWorkerThread::run QThread::currentThread = ") << QThread::currentThread();
    _lzWorkerAction();
    emit resultReady(result);
}

void LzWorkerThread::_lzWorkerAction()
{
//    qDebug() << QString::fromUtf8("run ......");

    // 死循环 （占用）
//    unsigned int n = 0xFFFFFFFF; // 0xFFFFFFFFFFFFFFFF
    unsigned int n = 30;
    do
    {
        qDebug() << QString::fromUtf8("run ......");
        QThread::msleep(1000/* * 3*/);
    } while(--n);
}

void LzWorkerThread::lzThreadRunning()
{
    qDebug() << QString::fromUtf8("lzThreadRunning QThread::currentThread = ") << QThread::currentThread();
}


void LzWorkerThread::lzThreadStarted()
{
    qDebug() << QString::fromUtf8("lzThreadStarted QThread::currentThread = ") << QThread::currentThread();
}

void LzWorkerThread::lzThreadFinished()
{
    qDebug() << QString::fromUtf8("lzThreadFinished QThread::currentThread = ") << QThread::currentThread();
}
