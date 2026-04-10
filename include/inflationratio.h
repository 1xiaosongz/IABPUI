//
// Created by Administrator on 2026/4/1.
//

#ifndef IABPUI_INFLATIONRATIO_H
#define IABPUI_INFLATIONRATIO_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class InflationRatio;
}

QT_END_NAMESPACE

class InflationRatio : public QWidget {
    Q_OBJECT

public:
    explicit InflationRatio(QWidget *parent = nullptr);

    ~InflationRatio() override;

private:
    Ui::InflationRatio *ui;
};


#endif //IABPUI_INFLATIONRATIO_H