#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>

class QActionGroup;
class QScrollArea;

class PaintArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createActions();
    void createMenus();

private:
    QAction *openAct = nullptr;
    QAction *saveAsAct = nullptr;
    QAction *exitAct = nullptr;
    QAction *brushWidthAct = nullptr;
    QAction *brushColorAct = nullptr;
    QAction *aboutAct = nullptr;
    QAction *aboutQtAct = nullptr;
    QAction *aboutPluginsAct = nullptr;
    QActionGroup *brushActionGroup = nullptr;

private slots:
    void open();
    bool saveAs();
    void brushColor();
    void brushWidth();
    void about();
    void aboutPlugins();

private:
    QMenu *fileMenu = nullptr;
    QMenu *brushMenu = nullptr;
    QMenu *shapesMenu = nullptr;
    QMenu *filterMenu = nullptr;
    QMenu *helpMenu = nullptr;

private:
    PaintArea *paintArea = nullptr;
    QScrollArea *scrollArea = nullptr;

private:
    QDir pluginsDir;
    QStringList pluginFileNames;
};
#endif // MAINWINDOW_H
