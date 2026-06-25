//
// Created by Administrator on 2026/5/28.
//

#ifndef IABPUI_TOPBAR_H
#define IABPUI_TOPBAR_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class TopBar;
}

QT_END_NAMESPACE

class TopBar : public QWidget {
    Q_OBJECT

public:
    explicit TopBar(QWidget *parent = nullptr);

    ~TopBar() override;

private:
    Ui::TopBar *ui;
};


#endif //IABPUI_TOPBAR_H
