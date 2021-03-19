#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_convert_clicked()
{
    //
    {
        qDebug() << QDateTime::currentDateTime().toString();
        // "yyyy-MM-dd hh:mm:ss.zzz"
        qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    }

    unsigned int ms = ui->lineEdit_ms->text().toUInt();
    {
        qDebug() << QString::fromUtf8("ms = %1").arg(ms);
    }

    {
        // 转 日期时间
        QDateTime dt = QDateTime::fromMSecsSinceEpoch(ms);;

        {
            qDebug() << dt.toString();
            qDebug() << dt.toString("yyyy-MM-dd hh:mm:ss.zzz");
        }

        ui->lineEdit_datetime->setText(dt.toString("yyyy-MM-dd hh:mm:ss.zzz"));
    }

    {
        // 转 时间
        QTime t = QTime::fromMSecsSinceStartOfDay(ms);

        {
            qDebug() << t.toString();
            qDebug() << t.toString("hh:mm:ss.zzz");
        }

        ui->lineEdit_time->setText(t.toString("hh:mm:ss.zzz"));
    }

    {
        // 转 UTC日期时间 // Qt::OffsetFromUTC
        QDateTime utc_dt = QDateTime::fromMSecsSinceEpoch(ms, Qt::OffsetFromUTC, 0);

        {
            qDebug() << utc_dt.toString();
            qDebug() << utc_dt.toString("yyyy-MM-dd hh:mm:ss.zzz");
        }

        ui->lineEdit_utc_datetime->setText(utc_dt.toString("yyyy-MM-dd hh:mm:ss.zzz"));
    }

    {
        // 转 00:00:00.000 时间
        QTime t0(0, 0, 0, 0);

        {
            qDebug() << t0.toString();
            qDebug() << t0.toString("hh:mm:ss.zzz");
        }

        ui->lineEdit_time_0->setText(t0.toString("hh:mm:ss.zzz"));
    }
}
