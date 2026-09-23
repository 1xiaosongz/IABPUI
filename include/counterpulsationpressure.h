//
// Created by Administrator on 2026/9/8.
//

#ifndef IABPUI_COUNTERPULSATIONPRESSURE_H
#define IABPUI_COUNTERPULSATIONPRESSURE_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class CounterpulsationPressure;
}

QT_END_NAMESPACE

class CounterpulsationPressure : public QWidget {
    Q_OBJECT

public:
    explicit CounterpulsationPressure(QWidget *parent = nullptr);

    ~CounterpulsationPressure() override;

private:
    Ui::CounterpulsationPressure *ui;
};


#endif //IABPUI_COUNTERPULSATIONPRESSURE_H
