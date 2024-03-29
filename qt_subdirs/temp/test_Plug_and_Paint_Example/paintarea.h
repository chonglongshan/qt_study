#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>

class BrushInterface;

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

public:
    int brushWidth() const { return thickness; }
    void setBrushWidth(int width);
private:
    int thickness = 3;

public:
    void setBrush(BrushInterface *brushInterface, const QString &brush);
private:
    BrushInterface *brushInterface = nullptr;
    QString brush;

public:
    void insertShape(const QPainterPath &path);
private:
    QPainterPath pendingPath;

public:
    QImage image() const { return theImage; }

protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    void setupPainter(QPainter &painter);
private:
    QPoint lastPos = {-1, -1};

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // PAINTAREA_H
