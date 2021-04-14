#include "lzchuankouzhushou.h"

#include <QDebug>

#define lzDebug() qDebug()

LzChuanKouZhuShou::LzChuanKouZhuShou(QObject *parent) : QObject(parent)
  , _lz_chuan_kou("", 0, ' ', 0, 0)
  , _lz_serial_port_opened(false)
{

}

// 发送并接收数据
QByteArray LzChuanKouZhuShou::lzFaSongBingJieShouShuJu(const LzChuanKouXinXi &chuan_kou, const QByteArray &data)
{
    QByteArray ret;

//    {
//        lzDebug() << _lz_chuan_kou.lzToString();
//        lzDebug() << chuan_kou.lzToString();
//    }

//    // 判定串口信息是否有变化
////    _lz_mutex_serial_port_open_close.lock();
//    if(_lz_chuan_kou != chuan_kou)
//    {
//        // 关闭串口
//        if(_lz_serial_port_opened)
//        {
//            _lz_serial_port_opened = false;
//            _lz_serial_port.close();
//        }
//        _lz_chuan_kou = chuan_kou;
//    }

//    // 是否需要打开串口
//    if(!_lz_serial_port_opened)
//    {
//        if (!_lz_serial_port.open(QIODevice::ReadWrite))
//        {
//            _lz_serial_port_opened = false;
//            lzDebug() << tr("Can't open %1, error code %2")
//                         .arg(_lz_chuan_kou.lzToString())
//                         .arg(_lz_serial_port.error());
//        }
//        else
//        {
//            _lz_serial_port_opened = true;
//        }
//    }
////    _lz_mutex_serial_port_open_close.unlock();

//    {
//        lzDebug() << _lz_chuan_kou.lzToString();
//        lzDebug() << chuan_kou.lzToString();
//    }

    // 进行串口数据收发
    if(_lzQingQiuChuanKou(chuan_kou))
    {
        int write_wait_timeout = 10*1000; // 毫秒
        int ready_read_wait_timeout = 10*1000;

        _lz_serial_port.write(data);
        if (_lz_serial_port.waitForBytesWritten(write_wait_timeout))
        {
            if (_lz_serial_port.waitForReadyRead(ready_read_wait_timeout))
            {
                QByteArray response_data = _lz_serial_port.readAll();
                while (_lz_serial_port.waitForReadyRead(100))
                    response_data += _lz_serial_port.readAll();

                ret = response_data;
            }
            else
            {
                lzDebug() << tr("Wait for ready read timeout %1 ms")
                             .arg(ready_read_wait_timeout);
            }
        }
        else
        {
            lzDebug() << tr("Wait for bytes written timeout %1 ms")
                         .arg(write_wait_timeout);
        }
    }

    // 发送的数据内容
    {
        //QString s = tr("发送的数据内容: ");
        //QString s = QString::fromUtf8("发送的数据内容: ");
        QString s = tr("send: ");
        for(int i = 0; i < data.size(); ++i)
        {
            s += QString("%1 ").arg(data.at(i), 2, 16, QLatin1Char('0')).toUpper();
        }
        lzDebug() << s;
    }
    // 接收的数据内容
    {
        //QString r = tr("接收的数据内容: ");
        //QString r = QString::fromUtf8("接收的数据内容: ");
        QString r = tr("receive: ");
        for(int i = 0; i < ret.size(); ++i)
        {
            r += QString("%1 ").arg(ret.at(i), 2, 16, QLatin1Char('0')).toUpper();
        }
        lzDebug() << r;
    }

    return ret;
}

void LzChuanKouZhuShou::_lzSetQSerialPort(QSerialPort &_lz_serial_port)
{
    //
    _lz_serial_port.setPortName(_lz_chuan_kou._lz_chuan_kou_hao);
    _lz_serial_port.setBaudRate(_lz_chuan_kou._lz_bo_te_lv);

    // 校验方式
    switch(_lz_chuan_kou._lz_jiao_yan_fang_shi)
    {
    case 'N':
        _lz_serial_port.setParity(QSerialPort::NoParity);
        break;
    case 'E':
        _lz_serial_port.setParity(QSerialPort::EvenParity);
        break;
    case 'O':
        _lz_serial_port.setParity(QSerialPort::OddParity);
        break;
    default:
        //lzDebug() << "QSerialPort::UnknownParity";
        //_lz_serial_port.setParity(QSerialPort::NoParity);
        _lz_serial_port.setParity(QSerialPort::UnknownParity);
        break;
    }

    // 数据位
    switch(_lz_chuan_kou._lz_shu_ju_wei)
    {
    case 5:
        _lz_serial_port.setDataBits(QSerialPort::Data5);
        break;
    case 6:
        _lz_serial_port.setDataBits(QSerialPort::Data6);
        break;
    case 7:
        _lz_serial_port.setDataBits(QSerialPort::Data7);
        break;
    case 8:
        _lz_serial_port.setDataBits(QSerialPort::Data8);
        break;
    default:
        //lzDebug() << "QSerialPort::UnknownDataBits";
        //_lz_serial_port.setDataBits(QSerialPort::Data8);
        _lz_serial_port.setDataBits(QSerialPort::UnknownDataBits);
        break;
    }

    // 停止位
    switch(_lz_chuan_kou._lz_ting_zhi_wei)
    {
    case 1:
        _lz_serial_port.setStopBits(QSerialPort::OneStop);
        break;
    case 2:
        _lz_serial_port.setStopBits(QSerialPort::TwoStop);
        break;
    case 3:
        _lz_serial_port.setStopBits(QSerialPort::OneAndHalfStop);
        break;
    default:
        //lzDebug() << "QSerialPort::UnknownStopBits";
        //_lz_serial_port.setStopBits(QSerialPort::OneStop);
        _lz_serial_port.setStopBits(QSerialPort::UnknownStopBits);
        break;
    }
}

bool LzChuanKouZhuShou::_lzQingQiuChuanKou(const LzChuanKouXinXi &chuan_kou)
{
    // 判定串口信息是否有变化
//    _lz_mutex_serial_port_open_close.lock();
    // 比较前
    {
        lzDebug() << _lz_chuan_kou.lzToString();
        lzDebug() << chuan_kou.lzToString();
    }

    if(_lz_chuan_kou != chuan_kou)
    {
        // 关闭串口
        if(_lz_serial_port_opened)
        {
            _lz_serial_port_opened = false;
            _lz_serial_port.close();
        }
        _lz_chuan_kou = chuan_kou;
    }

    // 比较后
    {
        lzDebug() << _lz_chuan_kou.lzToString();
        lzDebug() << chuan_kou.lzToString();
    }

    // 是否需要打开串口
    if(!_lz_serial_port_opened)
    {
        if (!_lz_serial_port.open(QIODevice::ReadWrite))
        {
            _lz_serial_port_opened = false;
            lzDebug() << tr("Can't open %1, error code %2")
                         .arg(_lz_chuan_kou.lzToString())
                         .arg(_lz_serial_port.error());
        }
        else
        {
            _lz_serial_port_opened = true;
            lzDebug() << tr("打开串口： ")
                         .arg(_lz_chuan_kou.lzToString());
        }
    }
    else
    {
        lzDebug() << tr("串口已经打开： ")
                     .arg(_lz_chuan_kou.lzToString());
    }
//    _lz_mutex_serial_port_open_close.unlock();

    return _lz_serial_port_opened;
}
