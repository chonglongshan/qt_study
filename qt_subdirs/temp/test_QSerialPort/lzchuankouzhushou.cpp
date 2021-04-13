#include "lzchuankouzhushou.h"

#include <QDebug>

LzChuanKouZhuShou::LzChuanKouZhuShou(QObject *parent) : QObject(parent)
{

}

// 发送并接收数据
QByteArray LzChuanKouZhuShou::lzFaSongBingJieShouShuJu(const LzChuanKouXinXi &chuan_kou, const QByteArray &data)
{
    QByteArray ret;

    {
        qDebug() << _lz_chuan_kou.lzToString();
        qDebug() << chuan_kou.lzToString();
    }

    // 判定串口信息是否有变化
    if(_lz_chuan_kou != chuan_kou)
    {
        // 关闭串口

        _lz_chuan_kou = chuan_kou;

        // 根据新的串口信息，打开串口
    }

    {
        qDebug() << _lz_chuan_kou.lzToString();
        qDebug() << chuan_kou.lzToString();
    }

    // 进行串口数据收发

    return ret;
}
