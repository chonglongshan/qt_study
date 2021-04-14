#ifndef LZCHUANKOUZHUSHOU_H
#define LZCHUANKOUZHUSHOU_H

#include "lzchuankouxinxi.h"

#include <QObject>
#include <QSerialPort>
#include <QMutex>

class LzChuanKouZhuShou : public QObject
{
    Q_OBJECT
public:
    explicit LzChuanKouZhuShou(QObject *parent = nullptr);

    // 发送并接收数据
//    QByteArray lzFaSongBingJieShouShuJu(LzChuanKouXinXi chuan_kou, QByteArray data);
    QByteArray lzFaSongBingJieShouShuJu(const LzChuanKouXinXi &chuan_kou, const QByteArray &data);

private:
    void _lzSetQSerialPort(QSerialPort &_lz_serial_port);
    bool _lzQingQiuChuanKou(const LzChuanKouXinXi &chuan_kou);

private:
    LzChuanKouXinXi _lz_chuan_kou;
    QSerialPort _lz_serial_port;
    bool _lz_serial_port_opened;
//    QMutex _lz_mutex_serial_port_open_close;
};

#endif // LZCHUANKOUZHUSHOU_H
