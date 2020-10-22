#ifndef GLOBLE_H
#define GLOBLE_H
#include <QString>
#include <QVariantList>
#include <QSqlDatabase>

extern int num01;
extern QString str;
extern QString username_qj;
extern QString password_qj;
extern QVariantList list_all_student;
extern QString sqluser;
extern QString sqlpass;
extern QVariantList list_all_dormstudent;

QSqlDatabase get_default_opened_db();
#endif // VARIATE_H



