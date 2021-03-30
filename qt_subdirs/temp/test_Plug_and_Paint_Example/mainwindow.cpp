#include "mainwindow.h"
#include "paintarea.h"
#include "plugindialog.h"
#include "interfaces.h"

#include <QtWidgets>

#define INCOMPLETE_FUNCTION qDebug() << tr("incomplete function: %1").arg(QT_MESSAGELOG_FUNC);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , paintArea(new PaintArea)
    , scrollArea(new QScrollArea)
{
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(paintArea);
    setCentralWidget(scrollArea);

    createActions();
    createMenus();
    loadPlugins();

    setWindowTitle(tr("Plug & Paint"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAsAct = new QAction(tr("&Save As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    connect(saveAsAct, &QAction::triggered, this, &MainWindow::saveAs);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, &QAction::triggered, this, &MainWindow::close);

    brushColorAct = new QAction(tr("&Brush Color..."), this);
    connect(brushColorAct, &QAction::triggered, this, &MainWindow::brushColor);

    brushWidthAct = new QAction(tr("&Brush Width..."), this);
    connect(brushWidthAct, &QAction::triggered, this, &MainWindow::brushWidth);

    brushActionGroup = new QActionGroup(this);

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);

    aboutPluginsAct = new QAction(tr("About &Plugins"), this);
    connect(aboutPluginsAct, &QAction::triggered, this, &MainWindow::aboutPlugins);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    brushMenu = menuBar()->addMenu(tr("&Brush"));
    brushMenu->addAction(brushColorAct);
    brushMenu->addAction(brushWidthAct);
    brushMenu->addSeparator();

    shapesMenu = menuBar()->addMenu(tr("&Shapes"));

    filterMenu = menuBar()->addMenu(tr("&Filter"));

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
    helpMenu->addAction(aboutPluginsAct);
}

void MainWindow::open()
{
    const QString fileName = QFileDialog::getOpenFileName(this,
                                                          tr("Open File"),
                                                          QDir::currentPath());
    if (!fileName.isEmpty()) {
        if (!paintArea->openImage(fileName)) {
            QMessageBox::information(this, tr("Plug & Paint"),
                                     tr("Cannot load %1.").arg(fileName));
            return;
        }
        paintArea->adjustSize();
    }
}

bool MainWindow::saveAs()
{
    const QString initialPath = QDir::currentPath() + "/untitled.png";

    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                          initialPath);
    if (fileName.isEmpty())
        return false;

    return paintArea->saveImage(fileName, "png");
}


void MainWindow::brushColor()
{
    const QColor newColor = QColorDialog::getColor(paintArea->brushColor());
    if (newColor.isValid())
        paintArea->setBrushColor(newColor);
}

void MainWindow::brushWidth()
{
    bool ok;
    const int newWidth = QInputDialog::getInt(this, tr("Plug & Paint"),
                                              tr("Select brush width:"),
                                              paintArea->brushWidth(),
                                              1, 50, 1, &ok);
    if (ok)
        paintArea->setBrushWidth(newWidth);
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Plug & Paint"),
            tr("The <b>Plug & Paint</b> example demonstrates how to write Qt "
               "applications that can be extended through plugins."));
}

void MainWindow::aboutPlugins()
{
    PluginDialog dialog(pluginsDir.path(), pluginFileNames, this);
    dialog.exec();
}

void MainWindow::loadPlugins()
{
    const auto staticInstances = QPluginLoader::staticInstances(); {qDebug() << staticInstances;}
    for (QObject *plugin : staticInstances)
        populateMenus(plugin);

    pluginsDir = QDir(qApp->applicationDirPath()); {qDebug() << pluginsDir;}

#if defined(Q_OS_WIN)
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        pluginsDir.cdUp();
#elif defined(Q_OS_MAC)
    if (pluginsDir.dirName() == "MacOS") {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
#endif
    pluginsDir.cd("plugins"); {qDebug() << pluginsDir;}

    const auto entryList = pluginsDir.entryList(QDir::Files); {qDebug() << entryList;}
    for (const QString &fileName : entryList) {
        {qDebug() << fileName;}
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName)); {qDebug() << loader.objectName();}
        QObject *plugin = loader.instance();
        if (plugin) {
            {qDebug() << plugin->objectName();}
            populateMenus(plugin);
            pluginFileNames += fileName;
        }
    }

    brushMenu->setEnabled(!brushActionGroup->actions().isEmpty());
    shapesMenu->setEnabled(!shapesMenu->actions().isEmpty());
    filterMenu->setEnabled(!filterMenu->actions().isEmpty());

    {qDebug() << pluginFileNames;}
}

void MainWindow::populateMenus(QObject *plugin)
{
    auto iBrush = qobject_cast<BrushInterface *>(plugin);
    if (iBrush)
        addToMenu(plugin, iBrush->brushes(), brushMenu, &MainWindow::changeBrush,
                  brushActionGroup);

    auto iShape = qobject_cast<ShapeInterface *>(plugin);
    if (iShape)
        addToMenu(plugin, iShape->shapes(), shapesMenu, &MainWindow::insertShape);

    auto iFilter = qobject_cast<FilterInterface *>(plugin);
    if (iFilter)
        addToMenu(plugin, iFilter->filters(), filterMenu, &MainWindow::applyFilter);
}

void MainWindow::insertShape()
{INCOMPLETE_FUNCTION}

void MainWindow::applyFilter()
{INCOMPLETE_FUNCTION}

void MainWindow::addToMenu(QObject *plugin, const QStringList &texts,
                           QMenu *menu, Member member,
                           QActionGroup *actionGroup)
//{INCOMPLETE_FUNCTION}
{
    for (const QString &text : texts) {
        auto action = new QAction(text, plugin); // 指定 plugin 为 QAction 的父类
        connect(action, &QAction::triggered, this, member);
        menu->addAction(action);

        if (actionGroup) {
            action->setCheckable(true);
            actionGroup->addAction(action);
        }
    }
}

void MainWindow::changeBrush()
{
    auto action = qobject_cast<QAction *>(sender());
    auto iBrush = qobject_cast<BrushInterface *>(action->parent()); // 获取 QAction 的父类，其为 plugin ，并转换为其支持的某接口。
    const QString brush = action->text();

    paintArea->setBrush(iBrush, brush);
}

