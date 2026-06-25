//
// Created by Administrator on 2026/5/28.
//

#ifndef IABPUI_STATUSBAR_H
#define IABPUI_STATUSBAR_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class StatusBar;
}

QT_END_NAMESPACE

class StatusBar : public QWidget {
    Q_OBJECT

public:
    explicit StatusBar(QWidget *parent = nullptr);

    ~StatusBar() override;

private:
    Ui::StatusBar *ui;
};


#endif //IABPUI_STATUSBAR_H
