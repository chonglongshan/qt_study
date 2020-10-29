#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 原项目使用了 Qt Extended 的 QtSingleApplication ，实现程序只运行一个实例。
    // 原项目使用了 Qt Extended 的 QtSingleApplication ，设置公司和软件版本信息等。

    // 原项目使用 QTextCodec 进行编码设置。

    // 原项目使用 QFont 进行字体设置。

    // 原项目使用 PluginManager 支持插件 。

    MainWindow w;
    w.show();
    return a.exec();
}
