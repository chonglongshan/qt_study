#include "mainwindow.h"

#include <QApplication>

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setStyle(QStyleFactory::create("simplestyle"));

    MainWindow w;
    w.resize(200, 50);
    w.show();
    return a.exec();
}
