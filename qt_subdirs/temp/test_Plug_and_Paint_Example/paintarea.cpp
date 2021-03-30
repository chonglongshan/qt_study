#include "paintarea.h"

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{

}

bool PaintArea::openImage(const QString &fileName)
{
    QImage image;
    if (!image.load(fileName))
        return false;

    setImage(image);
    return true;
}

void PaintArea::setImage(const QImage &image)
{
    theImage = image.convertToFormat(QImage::Format_RGB32);
    update();
    updateGeometry();
}
