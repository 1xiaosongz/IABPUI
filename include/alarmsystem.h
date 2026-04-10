//
// Created by Administrator on 2026/4/8.
//

#ifndef IABPUI_ALARMSYSTEM_H
#define IABPUI_ALARMSYSTEM_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class AlarmSystem;
}

QT_END_NAMESPACE

class AlarmSystem : public QWidget {
    Q_OBJECT

public:
    explicit AlarmSystem(QWidget *parent = nullptr);

    ~AlarmSystem() override;

private:
    Ui::AlarmSystem *ui;
};


#endif //IABPUI_ALARMSYSTEM_H