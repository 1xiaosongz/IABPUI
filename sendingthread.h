//
// Created by Administrator on 2026/4/14.
//

#ifndef IABPUI_SENDINGTHREAD_H
#define IABPUI_SENDINGTHREAD_H
#include <QObject>

class SendingThread :public QObject{
    Q_OBJECT
public:
    explicit SendingThread(QObject *parent = nullptr);

signals:
    // 通知主线程工作完成，携带计算结果
    void workFinished(int result);
    // 可选的进度信号
    void progressUpdated(int value);

public slots:
    // 耗时任务放在这里执行
    void doWork(int maxCount);
private:

};


#endif //IABPUI_SENDINGTHREAD_H