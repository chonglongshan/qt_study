#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    explicit PaintArea(QWidget *parent = nullptr);

public:
    bool openImage(const QString &fileName);
    void setImage(const QImage &image);
private:
    QImage theImage = {500, 400, QImage::Format_RGB32};

protected:
    void paintEvent(QPaintEvent *event) override;

public:
    QSize sizeHint() const override;

public:
    bool saveImage(const QString &fileName, const char *fileFormat);

public:
    QColor brushColor() const { return color; }
    void setBrushColor(const QColor &color);
private:
    QColor color = Qt::blue;
};

#endif // PAINTAREA_H
