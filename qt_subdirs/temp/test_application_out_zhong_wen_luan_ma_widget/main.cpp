#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //
    QString str("中文");
    qDebug() << str;
    qDebug() << "=========================================";
    qDebug() << QString("中文");
    qDebug() << QString::fromUtf8("中文");
    qDebug() << QString::fromLocal8Bit("中文");
    qDebug() << QString::fromLatin1("中文");

    MainWindow w;
    w.show();
    return a.exec();
}
