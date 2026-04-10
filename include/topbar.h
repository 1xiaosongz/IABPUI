//
// Created by Administrator on 2026/3/31.
//

#ifndef IABPUI_TOPBAR_H
#define IABPUI_TOPBAR_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Topbar;
}

QT_END_NAMESPACE

class Topbar : public QWidget {
    Q_OBJECT

public:
    explicit Topbar(QWidget *parent = nullptr);

    ~Topbar() override;

private:
    Ui::Topbar *ui;
};


#endif //IABPUI_TOPBAR_H