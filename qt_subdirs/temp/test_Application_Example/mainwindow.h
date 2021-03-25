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

    void loadFile(const QString &fileName);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void documentWasModified();

    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();

private:
    void createActions();
    void createStatusBar();
    void readSettings();
    void setCurrentFile(const QString &fileName);

    bool maybeSave();
    void writeSettings();

    bool saveFile(const QString &fileName);

private:
    QPlainTextEdit *textEdit;

    QString curFile;
};
#endif // MAINWINDOW_H
