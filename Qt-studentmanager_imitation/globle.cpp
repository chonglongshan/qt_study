#include "globle.h"
#include <QtDebug>

int num01;
QString str = "test";
QString username_qj = "";
 QString password_qj = "";
QVariantList list_all_student;
QString sqluser="root";
QString sqlpass="123456";
QVariantList list_all_dormstudent;

// 优化连接打开数据库的调用
QSqlDatabase get_default_opened_db()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains())
    {
        db = QSqlDatabase::database();
    }
    else
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("192.168.125.128");
        //db.setPort(3306);
        db.setDatabaseName("test");
        db.setUserName(sqluser);
        db.setPassword(sqlpass);
    }

    if (!db.open())
    {
        qDebug() << "Failed to connect to root mysql admin";
    }
    else
    {
        qDebug() << "open";
    }

    return db;
}

