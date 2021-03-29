#include "mainwindow.h"

#include <QtWidgets>

#define INCOMPLETE_FUNCTION qDebug() << tr("incomplete function: %1").arg(QT_MESSAGELOG_FUNC);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAsAct = new QAction(tr("&Save As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    connect(saveAsAct, &QAction::triggered, this, &MainWindow::saveAs);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, &QAction::triggered, this, &MainWindow::close);

    brushColorAct = new QAction(tr("&Brush Color..."), this);
    connect(brushColorAct, &QAction::triggered, this, &MainWindow::brushColor);

    brushWidthAct = new QAction(tr("&Brush Width..."), this);
    connect(brushWidthAct, &QAction::triggered, this, &MainWindow::brushWidth);

    brushActionGroup = new QActionGroup(this);

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);

    aboutPluginsAct = new QAction(tr("About &Plugins"), this);
    connect(aboutPluginsAct, &QAction::triggered, this, &MainWindow::aboutPlugins);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    brushMenu = menuBar()->addMenu(tr("&Brush"));
    brushMenu->addAction(brushColorAct);
    brushMenu->addAction(brushWidthAct);
    brushMenu->addSeparator();

    shapesMenu = menuBar()->addMenu(tr("&Shapes"));

    filterMenu = menuBar()->addMenu(tr("&Filter"));

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
    helpMenu->addAction(aboutPluginsAct);
}

void MainWindow::open()
{INCOMPLETE_FUNCTION}

bool MainWindow::saveAs()
{INCOMPLETE_FUNCTION return false;}

void MainWindow::brushColor()
{INCOMPLETE_FUNCTION}

void MainWindow::brushWidth()
{INCOMPLETE_FUNCTION}

void MainWindow::about()
{INCOMPLETE_FUNCTION}

void MainWindow::aboutPlugins()
{INCOMPLETE_FUNCTION}

