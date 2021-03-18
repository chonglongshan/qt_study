#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "log4qt/logger.h"
//#include "log4qt/ttcclayout.h"
#include "log4qt/consoleappender.h"
#include "log4qt/dailyrollingfileappender.h"
#include "log4qt/patternlayout.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    {
        auto logger = Log4Qt::Logger::rootLogger();

        // Create a layout
//        auto *layout = new Log4Qt::TTCCLayout();
//        layout->setName(QStringLiteral("My Layout"));
//        layout->activateOptions();
        auto *layout = new Log4Qt::PatternLayout("%d{yyyy-MM-dd HH:mm:ss.zzz} [%t] [%c] [%x] %m%n");
        layout->setName(QString::fromUtf8("My patternLayout"));
        layout->activateOptions();

        // Create a console appender
        Log4Qt::ConsoleAppender *consoleAppender = new Log4Qt::ConsoleAppender(layout, Log4Qt::ConsoleAppender::STDOUT_TARGET);
        consoleAppender->setName(QStringLiteral("My Appender"));
        consoleAppender->activateOptions();

        // Add appender on root logger
        logger->addAppender(consoleAppender);

        // 测试 DailyRollingFileAppender
        {
            // Create a Daily Rolling Appender
            //Log4Qt::DailyRollingFileAppender *dailyRollingAppender = new Log4Qt::DailyRollingFileAppender(layout, QString::fromUtf8("./log.txt"), QString::fromUtf8(".yyyy-MM-dd-hh"));
            //Log4Qt::DailyRollingFileAppender *dailyRollingAppender = new Log4Qt::DailyRollingFileAppender(layout, QString::fromUtf8("./log.txt"), QString::fromUtf8("'.'yyyy-MM-dd-hh")); // 正确的 DataPattern 内容

//            Log4Qt::DailyRollingFileAppender *dailyRollingAppender = new Log4Qt::DailyRollingFileAppender();
//            {
//                dailyRollingAppender->setLayout(layout);
//                dailyRollingAppender->setFile(QString::fromUtf8("./log.txt")); // 按分钟滚动产生的日志文件 log.txt.2021-03-18-10-55
//                // 重新启动程序， log.txt 总是被清空重写内容。
//                dailyRollingAppender->setAppendFile(true); // 设置使用追加内容方式， log.txt 不在清空内容，而是追加内容。
//            }

//            {
//                qDebug() << dailyRollingAppender->datePattern();
//                //dailyRollingAppender->setDatePattern(Log4Qt::DailyRollingFileAppender::HOURLY_ROLLOVER);
//                dailyRollingAppender->setDatePattern(Log4Qt::DailyRollingFileAppender::MINUTELY_ROLLOVER);
//                qDebug() << dailyRollingAppender->datePattern();
//            }

            Log4Qt::DailyRollingFileAppender *dailyRollingAppender = new Log4Qt::DailyRollingFileAppender(layout, QString::fromUtf8("./log.txt"), QString::fromUtf8("'.'yyyy-MM-dd-hh-mm"));
            qDebug() << dailyRollingAppender->datePattern();
            dailyRollingAppender->setAppendFile(true);

            dailyRollingAppender->setName(QStringLiteral("My Daily Rolling Appender"));
            dailyRollingAppender->activateOptions();

            // Add appender on root logger
            logger->addAppender(dailyRollingAppender);
        }
    }

//    {
//        auto logger = Log4Qt::Logger::rootLogger();

//        // Create a layout
////        auto *layout = new Log4Qt::TTCCLayout();
////        layout->setName(QStringLiteral("My Layout"));
////        layout->activateOptions();
//        auto *layout = new Log4Qt::PatternLayout("%d{yyyy-MM-dd HH:mm:ss.zzz} [%t] [%c] [%x] %m%n");
//        layout->setName(QString::fromUtf8("My patternLayout"));
//        layout->activateOptions();

//        // Create a Daily Rolling Appender
//        Log4Qt::DailyRollingFileAppender *dailyRollingAppender = new Log4Qt::DailyRollingFileAppender(layout, QString::fromUtf8("./log.txt"), QString::fromUtf8(".yyyy-MM-dd-hh"));
//        dailyRollingAppender->setName(QStringLiteral("My Daily Rolling Appender"));
//        dailyRollingAppender->activateOptions();

////        //
////        dailyRollingAppender->

//        // Add appender on root logger
//        logger->addAppender(dailyRollingAppender);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //
    auto logger = Log4Qt::Logger::rootLogger();
    logger->info() << QString::fromUtf8("log4qt");
}
