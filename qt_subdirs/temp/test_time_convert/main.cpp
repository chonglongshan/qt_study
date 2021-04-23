#include "mainwindow.h"

#include <QApplication>
#include <QDateTime>

extern QDateTime lz_show_date_time;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    lz_show_date_time = QDateTime::currentDateTime();
    return a.exec();
}
