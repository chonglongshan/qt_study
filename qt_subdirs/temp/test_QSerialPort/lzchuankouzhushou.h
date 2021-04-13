#ifndef LZCHUANKOUZHUSHOU_H
#define LZCHUANKOUZHUSHOU_H

#include "lzchuankouxinxi.h"

#include <QObject>

class LzChuanKouZhuShou : public QObject
{
    Q_OBJECT
public:
    explicit LzChuanKouZhuShou(QObject *parent = nullptr);

    // 发送并接收数据
//    QByteArray lzFaSongBingJieShouShuJu(LzChuanKouXinXi chuan_kou, QByteArray data);
    QByteArray lzFaSongBingJieShouShuJu(const LzChuanKouXinXi &chuan_kou, const QByteArray &data);

private:
    LzChuanKouXinXi _lz_chuan_kou;
};

#endif // LZCHUANKOUZHUSHOU_H
