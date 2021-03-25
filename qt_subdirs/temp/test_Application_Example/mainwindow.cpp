#include "mainwindow.h"

#include <QtWidgets>

#define INCOMPLETE_FUNCTION qDebug() << tr("incomplete function: %1").arg(QT_MESSAGELOG_FUNC);

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
{
    setWindowModified(textEdit->document()->isModified());
}

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

void MainWindow::newFile()
{
    if (maybeSave())
    {
        textEdit->clear();
        setCurrentFile(QString());
    }
}

void MainWindow::open()
{
    if (maybeSave())
    {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

void MainWindow::loadFile(const QString &fileName)
{INCOMPLETE_FUNCTION}

bool MainWindow::save()
{
    if (curFile.isEmpty())
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}

bool MainWindow::saveFile(const QString &fileName)
{
    INCOMPLETE_FUNCTION
    return false;
}

bool MainWindow::saveAs()
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return saveFile(dialog.selectedFiles().first());
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}
