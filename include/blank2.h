//
// Created by Administrator on 2026/4/8.
//

#ifndef IABPUI_BLANK2_H
#define IABPUI_BLANK2_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Blank2;
}

QT_END_NAMESPACE

class Blank2 : public QWidget {
    Q_OBJECT

public:
    explicit Blank2(QWidget *parent = nullptr);

    ~Blank2() override;

private:
    Ui::Blank2 *ui;
};


#endif //IABPUI_BLANK2_H