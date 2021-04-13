#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lzchuankouzhushou.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //
    LzChuanKouXinXi chuan_kou;
    LzChuanKouZhuShou zhu_shou;
    zhu_shou.lzFaSongBingJieShouShuJu(chuan_kou, QByteArray());
}

MainWindow::~MainWindow()
{
    delete ui;
}

