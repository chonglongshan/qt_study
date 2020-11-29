#include <QCoreApplication>


#include <stdio.h>

/*
要点提示:
1. float和unsigned long具有相同的数据结构长度
2. union据类型里的数据存放在相同的物理空间
*/
typedef union
{
    float fdata;
    unsigned long ldata;
}FloatLongType;

/*
将浮点数f转化为4个字节数据存放在byte[4]中
*/
void Float_to_Byte(float f,unsigned char byte[])
{
    FloatLongType fl;
    fl.fdata=f;
    byte[0]=(unsigned char)fl.ldata;
    byte[1]=(unsigned char)(fl.ldata>>8);
    byte[2]=(unsigned char)(fl.ldata>>16);
    byte[3]=(unsigned char)(fl.ldata>>24);
}
/*
将4个字节数据byte[4]转化为浮点数存放在*f中
*/
void Byte_to_Float(float *f,unsigned char byte[])
{
    FloatLongType fl;
    fl.ldata=0;
    fl.ldata=byte[3];
    fl.ldata=(fl.ldata<<8)|byte[2];
    fl.ldata=(fl.ldata<<8)|byte[1];
    fl.ldata=(fl.ldata<<8)|byte[0];
    *f=fl.fdata;
}

/*
测试函数
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    float f=10.0f;
    unsigned char byte[4]={0};

    printf("float data=%f\n",f);
    Float_to_Byte(f,byte);
    printf("byte: ");
    for(int i = 0; i < 4; ++i)
    {
        printf("0x%02X ", byte[i]);
    }
    printf("\n");
    f=789.123456f;
    printf("changed float data=%f\n",f);
    Byte_to_Float(&f,byte);
    printf("float data=%f\n",f);

    return a.exec();
}
