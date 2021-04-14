#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lzchuankouzhushou.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //
    LzChuanKouXinXi chuan_kou("COM3", 115200, 'N', 8, 1);
    LzChuanKouZhuShou zhu_shou;

    char request_data_array[] = {static_cast<char>(0xAA), 0x55, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    QByteArray request(request_data_array, sizeof (request_data_array)/sizeof(char));
    QByteArray response = zhu_shou.lzFaSongBingJieShouShuJu(chuan_kou, request);
    qDebug() << request;
    qDebug() << response;
}

MainWindow::~MainWindow()
{
    delete ui;
}

