//
// Created by Administrator on 2026/4/14.
//

#include "sendingthread.h"
#include <QThread>
#include <QDebug>

SendingThread::SendingThread(QObject *parent)
    : QObject(parent)
{
}
void SendingThread::doWork(int maxCount) {

    emit progressUpdated(1);
    emit workFinished(static_cast<int>(1));
}