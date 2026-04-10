//
// Created by Administrator on 2026/4/1.
//

#ifndef IABPUI_INFLATION_DEFLATION_TIMING_H
#define IABPUI_INFLATION_DEFLATION_TIMING_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Inflation_Deflation_Timing;
}

QT_END_NAMESPACE

class Inflation_Deflation_Timing : public QWidget {
    Q_OBJECT

public:
    explicit Inflation_Deflation_Timing(QWidget *parent = nullptr);

    ~Inflation_Deflation_Timing() override;

private:
    Ui::Inflation_Deflation_Timing *ui;
};


#endif //IABPUI_INFLATION_DEFLATION_TIMING_H