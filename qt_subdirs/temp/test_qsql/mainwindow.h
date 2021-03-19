#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_connect_database_clicked();

    void on_pushButton_step_1_clicked();

    void on_pushButton_step_2_clicked();

    void on_pushButton_step_3_clicked();

    void on_pushButton_step_4_clicked();

private:
    Ui::MainWindow *ui;

    //
    QSqlDatabase _lz_db;
    QString _lz_db_connection_name;
    QString _lz_db_name;
    QSqlQuery _lz_query;
};
#endif // MAINWINDOW_H
