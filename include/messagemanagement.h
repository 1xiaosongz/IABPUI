//
// Created by Administrator on 2026/4/8.
//

#ifndef IABPUI_MESSAGEMANAGEMENT_H
#define IABPUI_MESSAGEMANAGEMENT_H

#include <QWidget>
#include <QScroller>
class Level1Alarm;
QT_BEGIN_NAMESPACE

namespace Ui {
    class MessageManagement;
}

QT_END_NAMESPACE

class MessageManagement : public QWidget {
    Q_OBJECT

public:
    explicit MessageManagement(QWidget *parent = nullptr);

    ~MessageManagement() override;
    // 动态添加告警项的方法
    void addLevel1Alarm(const QString &alarmText = QString());
private:
    Ui::MessageManagement *ui;
};


#endif //IABPUI_MESSAGEMANAGEMENT_H