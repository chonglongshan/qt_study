#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 原项目封装了 void enableToolBar(QString text);  来使用 void QWidget::setEnabled(bool) 函数控制启用（亮）/禁用（灰）工具栏
    // 原项目使用了 setContextMenuPolicy(Qt::DefaultContextMenu); 来启用 void MainWindow::contextMenuEvent(QContextMenuEvent *event) 事件处理。其实默认（ Qt::DefaultContextMenu ）是启用的。

    setUpProjectTreeView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "qDebug(): void MainWindow::contextMenuEvent(QContextMenuEvent *event)";
    qInfo() << "qInfo(): void MainWindow::contextMenuEvent(QContextMenuEvent *event)";

    //QFile *file = new QFile("lz_log.txt");
    //QIODevice *lz_file = new QFile("lz_log.txt");
    QFile *file = new QFile("./lz_log.txt");
    //file->open(QIODevice::ReadWrite | QIODevice::Append);
    //QDebug(lz_file);
    //QDebug qdb = QDebug(lz_file);
    QDebug qdb = QDebug(file);
    qdb << "void MainWindow::contextMenuEvent(QContextMenuEvent *event)";

    QMessageLogger msg_logger(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC);
    msg_logger.debug() << "void MainWindow::contextMenuEvent(QContextMenuEvent *event)";

    //LZLogger

//    QMessageLogger msg_logger(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC);
//    msg_logger.context
//    QDebug qdb2 = QMessageLogger(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).debug();
//    qdb2.stream;

//    // new 出来的 QMenu ，后续如果没有主动释放，将一直保存在程序中。当其指定的父窗口销毁时，所有 new 出来的 QMenu 会自动随父窗口一起销毁。
//    QMenu *pMenu = new QMenu(this);

//    QAction *pAddGroupAct = new QAction(tr("增加组"), this);
//    pAddGroupAct->setStatusTip(tr("增加组"));
//    connect(pAddGroupAct, SIGNAL(triggered()), this, SLOT(tagIOGroupAdd()));
//    pMenu->addAction(pAddGroupAct);

//    pMenu->move(cursor().pos());
//    pMenu->show();

    QMenu *pMenu = new QMenu(this);

    QAction *pAddGroupAct = new QAction(tr("增加组"), this);
    pAddGroupAct->setStatusTip(tr("增加组"));
    connect(pAddGroupAct, SIGNAL(triggered()), this, SLOT(tagIOGroupAdd()));
    pMenu->addAction(pAddGroupAct);

    QAction *pRenameGroupAct = new QAction(tr("重命名"), this);
    pRenameGroupAct->setStatusTip(tr("重命名"));
    connect(pRenameGroupAct, SIGNAL(triggered()), this, SLOT(tagIOGroupRename()));
    pMenu->addAction(pRenameGroupAct);

    QAction *pDeleteGroupAct = new QAction(tr("删除组"), this);
    pDeleteGroupAct->setStatusTip(tr("删除组"));
    connect(pDeleteGroupAct, SIGNAL(triggered()), this, SLOT(tagIODeleteGroup()));
    pMenu->addAction(pDeleteGroupAct);

    QAction *pCopyGroupAct = new QAction(tr("复制组"), this);
    pCopyGroupAct->setStatusTip(tr("复制组"));
    connect(pCopyGroupAct, SIGNAL(triggered()), this, SLOT(tagIOGroupCopy()));
    pMenu->addAction(pCopyGroupAct);

    pMenu->move(cursor().pos());
    pMenu->show();

    // warning: unused parameter 'event'
    QMainWindow::contextMenuEvent(event);
}

// 工程管理器ui初始化
void MainWindow::setUpProjectTreeView()
{
    ui->treeViewProject->setHeaderHidden(true);

    pTreeViewProjectModel = new QStandardItemModel();
    pProjectItem = new QStandardItem(QIcon(":/images/pj_pro.png"), tr("未创建工程"));
    pProjectItem->setEditable(false);
    pSystemParameters = new QStandardItem(QIcon(":/images/pj_sys.png"), tr("系统参数"));
    pSystemParameters->setEditable(false);
    pProjectItem->appendRow(pSystemParameters);

    //////////////////////////////////////////////////////

    pCommunicationDevice = new QStandardItem(QIcon(":/images/pj_sys.png"), tr("通讯设备"));
    pCommunicationDevice->setEditable(false);
    pComDevice = new QStandardItem(QIcon(":/images/pj_com.png"), tr("串口设备"));
    pComDevice->setEditable(false);
    pCommunicationDevice->appendRow(pComDevice);
    pNetDevice = new QStandardItem(QIcon(":/images/pj_net.png"), tr("网络设备"));
    pNetDevice->setEditable(false);
    pCommunicationDevice->appendRow(pNetDevice);
    /*
  pBusDevice = new QStandardItem(QIcon(":/images/pj_bus.png"), tr("总线设备"));
  pBusDevice->setEditable(false);
  pCommunicationDevice->appendRow(pBusDevice);
  pOPCDevice = new QStandardItem(QIcon(":/images/pj_opc.png"), tr("OPC设备"));
  pOPCDevice->setEditable(false);
  pCommunicationDevice->appendRow(pOPCDevice);
  */
    pProjectItem->appendRow(pCommunicationDevice);

    pDataBaseConfig = new QStandardItem(QIcon(":/images/pj_sys.png"), tr("变量管理"));
    pDataBaseConfig->setEditable(false);
    pDevVariable = new QStandardItem(QIcon(":/images/pj_zone.png"), tr("设备变量"));
    pDevVariable->setEditable(false);

    pDataBaseConfig->appendRow(pDevVariable);
    pTmpVariable = new QStandardItem(QIcon(":/images/pj_zone.png"), tr("中间变量"));
    pTmpVariable->setEditable(false);
    pDataBaseConfig->appendRow(pTmpVariable);
    pSysVariable = new QStandardItem(QIcon(":/images/pj_zone.png"), tr("系统变量"));
    pSysVariable->setEditable(false);
    pDataBaseConfig->appendRow(pSysVariable);
    pProjectItem->appendRow(pDataBaseConfig);

    pDataBaseManager = new QStandardItem(QIcon(":/images/pj_sys.png"), tr("数据库管理"));
    pDataBaseManager->setEditable(false);
    pRealTimeDatabase = new QStandardItem(QIcon(":/images/db_rtdbview.png"), tr("实时数据库"));
    pRealTimeDatabase->setEditable(false);
    pDataBaseManager->appendRow(pRealTimeDatabase);
    pHistoryDatabase = new QStandardItem(QIcon(":/images/db_hisdbview.png"), tr("历史数据库"));
    pHistoryDatabase->setEditable(false);
    pDataBaseManager->appendRow(pHistoryDatabase);
    pProjectItem->appendRow(pDataBaseManager);

    pDrawPage = new QStandardItem(QIcon(":/images/pm_draw.png"), tr("画面"));
    pDrawPage->setEditable(false);
    pProjectItem->appendRow(pDrawPage);

    pLogicProgram = new QStandardItem(QIcon(":/images/pm_script.png"), tr("逻辑编程"));
    pLogicProgram->setEditable(false);

    pScriptEditor = new QStandardItem(QIcon(":/images/pj_script.png"), tr("脚本编辑器"));
    pScriptEditor->setEditable(false);
    pLogicProgram->appendRow(pScriptEditor);
    pProjectItem->appendRow(pLogicProgram);

    pTreeViewProjectModel->appendRow(pProjectItem);
    ui->treeViewProject->setModel(pTreeViewProjectModel);
    ui->treeViewProject->expandAll();
}

