#ifndef LZWORKERACTION_H
#define LZWORKERACTION_H

#include <QObject>

class LzWorkerAction : public QObject
{
    Q_OBJECT
public:
    explicit LzWorkerAction(QObject *parent = nullptr);
    ~LzWorkerAction();

    //
    void lzThreadStarted();
    void lzThreadFinished();
    void lzThreadRunning();

    //
    void lzMoveToMainThread();

signals:

public slots:
};

#endif // LZWORKERACTION_H
