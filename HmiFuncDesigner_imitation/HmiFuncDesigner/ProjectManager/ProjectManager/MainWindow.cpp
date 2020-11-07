#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 原项目封装了 void enableToolBar(QString text);  来使用 void QWidget::setEnabled(bool) 函数控制启用（亮）/禁用（灰）工具栏
    // 原项目使用了 setContextMenuPolicy(Qt::DefaultContextMenu); 来启用 void MainWindow::contextMenuEvent(QContextMenuEvent *event) 事件处理。其实默认（ Qt::DefaultContextMenu ）是启用的。

    //ui->treeViewProject->setHeaderHidden(true);
    pTreeViewProjectModel = new QStandardItemModel();

//    // setHeaderData 什么作用？用不来？
//    pTreeViewProjectModel->setHeaderData(0, Qt::Horizontal, "xyz");
//    pTreeViewProjectModel->setHeaderData(1, Qt::Horizontal, "xyz");
//    pTreeViewProjectModel->setHeaderData(0, Qt::Vertical, "xyz");
//    pTreeViewProjectModel->setHeaderData(1, Qt::Vertical, "xyz");
    // 可以使用其 Model 的 setHorizontalHeaderLabels(const QStringList &labels) 来更改标头文本。
    pTreeViewProjectModel->setHorizontalHeaderLabels(QStringList() << "xyz");

    pProjectItem = new QStandardItem(QIcon(":/images/pj_pro.png"), tr("未创建工程"));
    pProjectItem->setEditable(false);
    pSystemParameters = new QStandardItem(QIcon(":/images/pj_sys.png"), tr("系统参数"));
    //pSystemParameters->setEditable(false);

    pTreeViewProjectModel->appendRow(pProjectItem);
    //pTreeViewProjectModel->appendRow(pSystemParameters);
    pProjectItem->appendRow(pSystemParameters);

    ui->treeViewProject->setModel(pTreeViewProjectModel);
    ui->treeViewProject->expandAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
//    qDebug() << "void MainWindow::contextMenuEvent(QContextMenuEvent *event)";

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

