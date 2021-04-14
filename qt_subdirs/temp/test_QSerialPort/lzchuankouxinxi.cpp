#include "lzchuankouxinxi.h"

#include <QTextStream>

LzChuanKouXinXi::LzChuanKouXinXi(QObject *parent) : QObject(parent)
  , _lz_chuan_kou_hao("COM1")
  , _lz_bo_te_lv(9600)
  , _lz_jiao_yan_fang_shi('N')
  , _lz_shu_ju_wei(8)
  , _lz_ting_zhi_wei(1)
{

}

LzChuanKouXinXi::LzChuanKouXinXi(QString chuan_kou_hao
                                 , int bo_te_lv
                                 , char jiao_yan_fang_shi
                                 , int shu_ju_wei
                                 , int ting_zhi_wei)
    : _lz_chuan_kou_hao(chuan_kou_hao)
    , _lz_bo_te_lv(bo_te_lv)
    , _lz_jiao_yan_fang_shi(jiao_yan_fang_shi)
    , _lz_shu_ju_wei(shu_ju_wei)
    , _lz_ting_zhi_wei(ting_zhi_wei)
{

}

bool operator==(const LzChuanKouXinXi &xx1, const LzChuanKouXinXi &xx2)
{
    if((xx1._lz_chuan_kou_hao == xx2._lz_chuan_kou_hao)
            && (xx1._lz_bo_te_lv == xx2._lz_bo_te_lv)
            && (xx1._lz_jiao_yan_fang_shi == xx2._lz_jiao_yan_fang_shi)
            && (xx1._lz_shu_ju_wei == xx2._lz_shu_ju_wei)
            && (xx1._lz_ting_zhi_wei == xx2._lz_ting_zhi_wei))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const LzChuanKouXinXi &xx1, const LzChuanKouXinXi &xx2)
{
    return !(xx1 == xx2);
}

//QDataStream &operator<<(QDataStream &s, const LzChuanKouXinXi &x)
//{
//    s << x._lz_chuan_kou_hao
//      << x._lz_bo_te_lv
//      << x._lz_jiao_yan_fang_shi
//      << x._lz_shu_ju_wei
//      << x._lz_ting_zhi_wei;
//    return s;
//}

QString LzChuanKouXinXi::lzToString() const
{
    QString s;
    QTextStream ts(&s);
    ts << _lz_chuan_kou_hao << ", "
       << _lz_bo_te_lv << ", "
       << _lz_jiao_yan_fang_shi << ", "
       << _lz_shu_ju_wei << ", "
       << _lz_ting_zhi_wei;
    return (*(ts.string()));
}
