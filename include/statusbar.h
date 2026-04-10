//
// Created by Administrator on 2026/3/31.
//

#ifndef IABPUI_STATUSBAR_H
#define IABPUI_STATUSBAR_H

#include <QWidget>
// #include "homepage.h"
class Homepage;
QT_BEGIN_NAMESPACE

namespace Ui {
    class Statusbar;
}

QT_END_NAMESPACE

class Statusbar : public QWidget {
    Q_OBJECT

public:
    explicit Statusbar(QWidget *parent = nullptr);
    ~Statusbar() override;
    Homepage *homepage;
private:
    Ui::Statusbar *ui;
};


#endif //IABPUI_STATUSBAR_H