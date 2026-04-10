//
// Created by Administrator on 2026/4/9.
//

#ifndef IABPUI_LEVEL1ALARM_H
#define IABPUI_LEVEL1ALARM_H

#include <QFrame>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Level1Alarm;
}

QT_END_NAMESPACE

class Level1Alarm : public QFrame {
    Q_OBJECT

public:
    explicit Level1Alarm(QWidget *parent = nullptr);

    ~Level1Alarm() override;

private:
    Ui::Level1Alarm *ui;
};


#endif //IABPUI_LEVEL1ALARM_H