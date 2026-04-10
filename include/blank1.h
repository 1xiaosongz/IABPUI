//
// Created by Administrator on 2026/4/8.
//

#ifndef IABPUI_BLANK1_H
#define IABPUI_BLANK1_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Blank1;
}

QT_END_NAMESPACE

class Blank1 : public QWidget {
    Q_OBJECT

public:
    explicit Blank1(QWidget *parent = nullptr);

    ~Blank1() override;

private:
    Ui::Blank1 *ui;
};


#endif //IABPUI_BLANK1_H