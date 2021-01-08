#include "lzthread.h"

#include <QDebug>

LzThread::LzThread(QObject *parent) : QThread(parent)
{
    qDebug() << QString::fromUtf8("LzThread::LzThread");
}

LzThread::~LzThread()
{
    qDebug() << QString::fromUtf8("LzThread::~LzThread");
}
