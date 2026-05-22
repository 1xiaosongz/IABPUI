//
// Created by Administrator on 2026/4/7.
//

#ifndef IABPUI_TRIGGERMODE_H
#define IABPUI_TRIGGERMODE_H

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE

namespace Ui {
    class TriggerMode;
}

QT_END_NAMESPACE

class TriggerMode : public QWidget {
    Q_OBJECT

public:
    explicit TriggerMode(QWidget *parent = nullptr);

    ~TriggerMode() override;
    void setLetterSpacing(QLabel* label,int spacing);
    // void test();
public slots:
    // void on_ECG_Button_clicked();
    // void on_Pressure_Button_clicked();

private:
    Ui::TriggerMode *ui;
};


#endif //IABPUI_TRIGGERMODE_H