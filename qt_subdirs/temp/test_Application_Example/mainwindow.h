#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPlainTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void documentWasModified();

private:
    void createActions();
    void createStatusBar();
    void readSettings();
    void setCurrentFile(const QString &fileName);

private:
    QPlainTextEdit *textEdit;
};
#endif // MAINWINDOW_H
