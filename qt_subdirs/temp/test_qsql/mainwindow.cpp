#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
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


void MainWindow::on_pushButton_connect_database_clicked()
{
    // 创建数据库连接
    QString db_connection_name = QString("dian_zi_fei_chan_xian");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", db_connection_name);
    QString db_name = QString("dian_zi_fei_chan_xian_%1.db").arg(0);
    db.setDatabaseName(db_name);
    // 打开数据库连接
    if (!db.open())
    {
        QSqlError err = db.lastError();
        qDebug() << QString::fromUtf8("QSqlError : ") << err.text();
        QSqlDatabase::removeDatabase(db_connection_name);
    }
    else
    {
        // 数据库 DDL 操作
        QString sql_table_exist = QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("dian_zi_fei_shu_ju");
        //QSqlQuery query(db_connection_name);
        //QSqlQuery query(QSqlDatabase::database(db_connection_name));
        QSqlQuery query(db);
        if(!query.exec(sql_table_exist))
        {
            QSqlError err = query.lastError();
            qDebug() << QString::fromUtf8("QSqlError : ") << err.text();
            qDebug() << QString::fromUtf8("QSqlQuery : ") << query.executedQuery();
            qDebug() << QString::fromUtf8("QSqlQuery : ") << query.lastQuery();
        }
        else
        {
            qDebug() << QString::fromUtf8("QSqlQuery : ") << query.executedQuery();
            qDebug() << QString::fromUtf8("QSqlQuery : ") << query.lastQuery();

            // 提取 DDL 操作结果
            if(query.next())
            {
                bool is_table_exist = query.value(0).toInt();
                if(!is_table_exist)
                {
                    qDebug() << "table does not exist";
                }
                else
                {
                    qDebug() << "table exists";
                }
            }
        }
    }
}

void MainWindow::on_pushButton_step_1_clicked()
{
    // 创建数据库连接
    _lz_db_connection_name = QString("dian_zi_fei_chan_xian");
    _lz_db = QSqlDatabase::addDatabase("QSQLITE", _lz_db_connection_name);
    _lz_db_name = QString("dian_zi_fei_chan_xian_%1.db").arg(0);
    _lz_db.setDatabaseName(_lz_db_name);

    if(QSqlError::NoError == _lz_db.lastError().type())
    {
        qDebug() << QString::fromUtf8("QSqlError::NoError , ") << _lz_db.lastError().text();
    }
    else
    {
        qDebug() << QString::fromUtf8("QSqlError: ") << _lz_db.lastError().text();
    }
}

void MainWindow::on_pushButton_step_2_clicked()
{
    // 打开数据库连接
    if (!_lz_db.open()) // 如果数据库文件不存在，会自动创建数据库文件。
    {
        QSqlError err = _lz_db.lastError();
        qDebug() << QString::fromUtf8("QSqlError : ") << err.text();
        QSqlDatabase::removeDatabase(_lz_db_connection_name);
    }
    else
    {
        qDebug() << QString::fromUtf8("打开数据库连接 成功 OK");
        qDebug() << QString::fromLatin1("打开数据库连接 成功");
        qDebug() << "打开数据库连接 成功";
        qDebug() << QString::fromUtf8("打开数据库连接 成功").toLatin1();
        qDebug() << QString::fromUtf8("打开数据库连接 成功").toLocal8Bit();
        qDebug() << QString::fromUtf8("打开数据库连接 成功").toStdString().c_str();
        qDebug() << QString::fromLocal8Bit("打开数据库连接 成功");
        qDebug() << QString("打开数据库连接 成功").toStdString().c_str();
        qDebug() << QString::fromWCharArray(L"打开数据库连接 成功").toStdString().c_str();
        qDebug() << QString::fromStdString("打开数据库连接 成功").toStdString().c_str();
        qDebug() << QString::fromStdString("打开数据库连接 成功");
    }
}

void MainWindow::on_pushButton_step_3_clicked()
{
    if (_lz_db.isOpen())
    {
        // 数据库 DDL 操作
        QString sql_table_exist = QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("dian_zi_fei_shu_ju");
        _lz_query = QSqlQuery(_lz_db);
        if(!_lz_query.exec(sql_table_exist))
        {
            QSqlError err = _lz_query.lastError();
            qDebug() << QString::fromUtf8("QSqlError : ") << err.text();
            qDebug() << QString::fromUtf8("QSqlQuery : ") << _lz_query.executedQuery();
            qDebug() << QString::fromUtf8("QSqlQuery : ") << _lz_query.lastQuery();
        }
        else
        {
            qDebug() << QString::fromUtf8("QSqlQuery : ") << _lz_query.executedQuery();
            qDebug() << QString::fromUtf8("QSqlQuery : ") << _lz_query.lastQuery();

            qDebug() << QString::fromUtf8("数据库 DDL 操作 成功 OK");
        }
    }
    else
    {
        qDebug() << QString::fromUtf8("请先 打开数据库连接 ERROR");
    }
}

void MainWindow::on_pushButton_step_4_clicked()
{
    if(_lz_query.isActive())
    {
        // 提取 DDL 操作结果
        if(_lz_query.next())
        {
            bool is_table_exist = _lz_query.value(0).toInt();
            if(!is_table_exist)
            {
                qDebug() << "table does not exist";
            }
            else
            {
                qDebug() << "table exists";
            }
        }
    }
    else
    {
        qDebug() << QString::fromUtf8("请先 数据库 DDL 操作 ERROR");
    }
}
