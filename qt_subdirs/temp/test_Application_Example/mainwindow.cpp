#include "mainwindow.h"

#include <QtWidgets>

#define INCOMPLETE_FUNCTION qDebug() << QString("incomplete function: %1").arg(QT_MESSAGELOG_FUNC);

MainWindow::MainWindow(QWidget *parent)
    : textEdit(new QPlainTextEdit)
{
    setCentralWidget(textEdit);

    createActions();
    createStatusBar();

    readSettings();

    connect(textEdit->document(), &QTextDocument::contentsChanged,
            this, &MainWindow::documentWasModified);

//#ifndef QT_NO_SESSIONMANAGER
//    QGuiApplication::setFallbackSessionManagementEnabled(false);
//    connect(qApp, &QGuiApplication::commitDataRequest,
//            this, &MainWindow::commitData);
//#endif

    setCurrentFile(QString());
//    setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::~MainWindow()
{
}

void MainWindow::documentWasModified()
{INCOMPLETE_FUNCTION}

void MainWindow::createActions()
{INCOMPLETE_FUNCTION}

void MainWindow::createStatusBar()
{INCOMPLETE_FUNCTION}

void MainWindow::readSettings()
{INCOMPLETE_FUNCTION}

void MainWindow::setCurrentFile(const QString &fileName)
{INCOMPLETE_FUNCTION}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave())
    {
        writeSettings();
        event->accept();
    } else
    {
        event->ignore();
    }
}

bool MainWindow::maybeSave()
{
    INCOMPLETE_FUNCTION
    return false;
}

void MainWindow::writeSettings()
{INCOMPLETE_FUNCTION}
