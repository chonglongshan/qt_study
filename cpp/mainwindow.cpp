#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

