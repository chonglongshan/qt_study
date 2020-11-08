#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private:
    void setUpProjectTreeView();

private:
    Ui::MainWindow *ui;

private:
    QStandardItemModel *pTreeViewProjectModel;

    QStandardItem *pProjectItem;
    QStandardItem *pSystemParameters;
    QStandardItem *pCommunicationDevice;
    QStandardItem *pComDevice;
    QStandardItem *pNetDevice;
    //QStandardItem *pBusDevice;
    //QStandardItem *pOPCDevice;
    QStandardItem *pDataBaseConfig;
    QStandardItem *pDevVariable;
    //QList<QStandardItem *> pDevVariableTabList;
    QStandardItem *pTmpVariable;
    QStandardItem *pSysVariable;
    QStandardItem *pDataBaseManager;
    QStandardItem *pRealTimeDatabase;
    QStandardItem *pHistoryDatabase;
    QStandardItem *pDrawPage;
    QStandardItem *pLogicProgram;
    QStandardItem *pScriptEditor;
    //QStandardItem *pSystemTool;
};
#endif // MAINWINDOW_H
