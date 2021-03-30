#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    explicit PaintArea(QWidget *parent = nullptr);

    bool openImage(const QString &fileName);
    void setImage(const QImage &image);

    QSize sizeHint() const override;

    bool saveImage(const QString &fileName, const char *fileFormat);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:

private:
    QImage theImage = {500, 400, QImage::Format_RGB32};
};

#endif // PAINTAREA_H
