//
// Created by Administrator on 2026/3/31.
//

#ifndef IABPUI_BOTTOMNAVIGATIONBAR_H
#define IABPUI_BOTTOMNAVIGATIONBAR_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class BottomNavigationBar;
}

QT_END_NAMESPACE

class BottomNavigationBar : public QWidget {
    Q_OBJECT

public:
    explicit BottomNavigationBar(QWidget *parent = nullptr);

    ~BottomNavigationBar() override;
    void refreshStyle(QWidget* w);
    void refreshStyle1(QWidget *widget);
    void testModeButtonImages();
    void testTriggerModeButtonImages();
    void testInflationDeflationTimingImages();
    void testInflationRatioImages();
    void testCounterpulsationPressureImages();
    void testSetButtonImages();
    void testFreezeWindowImages();
    void testPressureZeroingImages();
    void testHelp_ButtonImages();
    void testBottomNavigationBar_Help_ButtonImages();
    void testSwitch_ButtonImages();
    void CounterpulsationPumpImages();
    void Replenish_Again_HeImages();
private:

    Ui::BottomNavigationBar *ui;
};


#endif //IABPUI_BOTTOMNAVIGATIONBAR_H