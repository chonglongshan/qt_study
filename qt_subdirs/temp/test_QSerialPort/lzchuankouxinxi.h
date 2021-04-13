#ifndef LZCHUANKOUXINXI_H
#define LZCHUANKOUXINXI_H

#include <QObject>

class LzChuanKouXinXi : public QObject
{
    Q_OBJECT
public:
    explicit LzChuanKouXinXi(QObject *parent = nullptr);

    //
    LzChuanKouXinXi &operator=(const LzChuanKouXinXi &other)
    {
        _lz_chuan_kou_hao = other._lz_chuan_kou_hao;
        _lz_bo_te_lv = other._lz_bo_te_lv;
        _lz_jiao_yan_fang_shi = other._lz_jiao_yan_fang_shi;
        _lz_shu_ju_wei = other._lz_shu_ju_wei;
        _lz_ting_zhi_wei = other._lz_ting_zhi_wei;

        return *this;
    }

    //
    QString lzToString() const;

private:
    QString _lz_chuan_kou_hao;
    int _lz_bo_te_lv;
    char _lz_jiao_yan_fang_shi;
    int _lz_shu_ju_wei;
    int _lz_ting_zhi_wei;

//    friend class LzChuanKouZhuShou;
    friend bool operator==(const LzChuanKouXinXi &xx1, const LzChuanKouXinXi &xx2);
    friend bool operator!=(const LzChuanKouXinXi &xx1, const LzChuanKouXinXi &xx2);
//    friend QDataStream &operator<<(QDataStream &s, const LzChuanKouXinXi &x);
};

//QDataStream &operator<<(QDataStream &s, const LzChuanKouXinXi &x);

#endif // LZCHUANKOUXINXI_H
