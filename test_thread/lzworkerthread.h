#ifndef LZWORKERTHREAD_H
#define LZWORKERTHREAD_H

#include <QThread>

class LzWorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit LzWorkerThread(QObject *parent = nullptr);
    ~LzWorkerThread();

    void run() override;

    void lzThreadRunning();
    void lzThreadStarted();
    void lzThreadFinished();

private:
    void _lzWorkerAction();

signals:
    void resultReady(const QString &s);

public slots:
};

#endif // LZWORKERTHREAD_H
