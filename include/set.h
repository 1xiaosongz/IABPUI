//
// Created by Administrator on 2026/4/8.
//

#ifndef IABPUI_SET_H
#define IABPUI_SET_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Set;
}

QT_END_NAMESPACE

class Set : public QWidget {
    Q_OBJECT

public:
    explicit Set(QWidget *parent = nullptr);

    ~Set() override;

private:
    Ui::Set *ui;
};


#endif //IABPUI_SET_H