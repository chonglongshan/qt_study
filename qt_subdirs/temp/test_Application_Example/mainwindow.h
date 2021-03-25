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

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void documentWasModified();

private:
    void createActions();
    void createStatusBar();
    void readSettings();
    void setCurrentFile(const QString &fileName);

    bool maybeSave();
    void writeSettings();

private:
    QPlainTextEdit *textEdit;
};
#endif // MAINWINDOW_H
