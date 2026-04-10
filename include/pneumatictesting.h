 //
// Created by Administrator on 2026/4/10.
//

#ifndef IABPUI_PNEUMATICTESTING_H
#define IABPUI_PNEUMATICTESTING_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class PneumaticTesting;
}

QT_END_NAMESPACE

class PneumaticTesting : public QWidget {
    Q_OBJECT

public:
    explicit PneumaticTesting(QWidget *parent = nullptr);

    ~PneumaticTesting() override;

private:
    Ui::PneumaticTesting *ui;
};


#endif //IABPUI_PNEUMATICTESTING_H