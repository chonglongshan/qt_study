#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <iostream>
#include <string>
#include <QStringLiteral>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    //??????
//#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
//#if _MSC_VER
//    QTextCodec *codec = QTextCodec::codecForName("GBK");
//#else
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//#endif
//    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForTr(codec);
//#else
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec *codec = QTextCodec::codecForName("GB2312");
//    QTextCodec *codec = QTextCodec::codecForName("GBK");
//    QTextCodec *codec = QTextCodec::codecForName("ASCII");
//    QTextCodec *codec = QTextCodec::codecForName("ISO-8859-1");
//    QTextCodec::setCodecForLocale(codec);
//#endif

    qDebug() << "str";
    qDebug() << "=========================================";

    //
    QString str("中文");
    qDebug() << str;
    qDebug() << "=========================================";
    qDebug() << QString("中文");
    qDebug() << QString::fromUtf8("中文");
    qDebug() << QString::fromLocal8Bit("中文");
    qDebug() << QString::fromLatin1("中文");
    qDebug() << QString::fromUtf8("中文").toStdString().c_str() ;

    qDebug() << "=========================================";
    std::cout << "......" << std::endl;
    std::cout << "中文" << std::endl;
    std::cout << QString::fromUtf8("中文").toStdString().c_str() << std::endl;
    std::cout << QString("中文").toStdString().c_str() << std::endl;
    std::cout << QString("中文").toLocal8Bit().toStdString().c_str() << std::endl;
    std::cout << QString("中文").toLatin1().toStdString().c_str() << std::endl;

    qDebug() << "=========================================";
    qDebug() << QString::fromUtf8(QString::fromUtf8("中文").toStdString().c_str());
//    qDebug() << QString::fromStdWString(L"??");
    qDebug() << "中文";
    qDebug() << QString::fromUtf8("中文").toLatin1();
    qDebug() << QString::fromLocal8Bit("中文").toUtf8();
    qDebug() << QString::fromLatin1("中文").toUtf8();
    qDebug() << QString::fromUtf8("中文").toUtf8();
    qDebug() << QString("中文").toUtf8();
    qDebug() << QString("中文").toLocal8Bit().toStdString().c_str();
    qDebug() << QString::fromLocal8Bit("中文").toLocal8Bit().toStdString().c_str();

    qDebug() << "=========================================";
    qDebug() << QString::fromUtf8("中文").toStdString().c_str();
    qDebug() << QTextCodec::codecForLocale()->name();
//    qDebug() << QStringLiteral("中文").toLocal8Bit();

    qDebug("%s", QString("中文").toStdString().c_str());
    qDebug() << QString::fromUtf8("中文").toStdString().c_str();
    qDebug() << QString::fromLatin1("中文").toStdString().c_str();
    qDebug() << QString::fromLocal8Bit("中文").toStdString().c_str();
    qDebug() << "中文";

    return a.exec();
}
