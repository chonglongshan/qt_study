#ifndef LZTHREAD_H
#define LZTHREAD_H

#include <QThread>

class LzThread : public QThread
{
    Q_OBJECT
public:
    explicit LzThread(QObject *parent = nullptr);
    ~LzThread();

signals:

public slots:
};

#endif // LZTHREAD_H
