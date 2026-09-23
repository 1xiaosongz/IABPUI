//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BottomNavigationBar.h" resolved

#include "bottomnavigationbar.h"

#include <qstyle.h>

#include <QGraphicsDropShadowEffect>

#include "ui_bottomnavigationbar.h"
/*
 *底端
 */

BottomNavigationBar::BottomNavigationBar(QWidget *parent) : QWidget(parent), ui(new Ui::BottomNavigationBar) {
    ui->setupUi(this);
    ui->CounterpulsationPump_Button->setProperty("mode","CounterpulsationPump_Button_False");
    ui->Mode_Button->setProperty("mode","Mode_Unknown_False");
    ui->TriggerMode_Button->setProperty("mode","ECG_Stop");
    ui->InflationRatio_Button->setProperty("mode","1_1_False");
    ui->Inflation_Deflation_Timing_Label->setProperty("mode","Inflation_Deflation_Timing_Stop");
    ui->Counterpulsation_Pressure_Button->setProperty("mode","Counterpulsation_Pressure_Eighth_Gear_True");
    ui->Inflatable_Numbers_label->setText("90");
    ui->Inflatable_Numbers_label->setProperty("mode","38px,colour138,147,160");
    ui->Deflating_Number_label->setText("90");
    ui->Deflating_Number_label->setProperty("mode","38px,colour138,147,160");
    ui->Label->setProperty("mode","Label_BottomNavigationBar");
    ui->FreezeWindow_Label->setProperty("mode","FreezeWindow_Label_False"); 
    ui->PressureZeroing_Label->setProperty("mode","PressureZeroing_Label_False");
    ui->BottomNavigationBar_Help_Button_Label->setProperty("mode","BottomNavigationBar_Help_Button_Label_Label_False");
    ui->Set_Button_Label->setProperty("mode","Set_Button_Label_False");
    ui->Switch_Button_Label->setProperty("mode","Switch_Button_Label_False");
    ui->Bottom_BalloonVolume_Label->setProperty("mode","18px,colour172,181,197");
    ui->Bottom_BalloonVolume_Label->setText("40cc");
    ui->label->setProperty("mode","18px,colour172,181,197");
    ui->label_2->setProperty("mode","18px,colour172,181,197");
    ui->label_3->setProperty("mode","18px,colour172,181,197");
    ui->label_4->setProperty("mode","18px,colour172,181,197");
    ui->label_5->setProperty("mode","18px,colour172,181,197");
    ui->Anti_embolismPressureSetting->setText("反搏压设置");
    ui->Anti_embolismPressureSetting->setProperty("mode","18px,colour172,181,197");
    ui->label_7->setProperty("mode","18px,colour172,181,197");
    ui->label_8->setProperty("mode","18px,colour172,181,197");
    ui->label_9->setProperty("mode","18px,colour172,181,197");
    ui->label_10->setProperty("mode","18px,colour172,181,197");
    ui->label_11->setProperty("mode","18px,colour172,181,197");
    ui->label_12->setProperty("mode","18px,colour172,181,197");
    ui->label_13->setProperty("mode","18px,colour172,181,197");
    auto inflatableShadow = new QGraphicsDropShadowEffect(this);
    inflatableShadow->setOffset(0, 4);
    inflatableShadow->setColor(QColor(0, 0, 0, 64));
    ui->Inflatable_Numbers_label->setGraphicsEffect(inflatableShadow);
    auto deflatingShadow = new QGraphicsDropShadowEffect(this);
    deflatingShadow->setOffset(0, 4);
    deflatingShadow->setColor(QColor(0, 0, 0, 64));
    ui->Deflating_Number_label->setGraphicsEffect(deflatingShadow);
    ui->Replenish_Again_He_Label->setProperty("mode","Replenish_Again_He_Label_True");



    refreshStyle1(ui->Mode_Button);
    refreshStyle1(ui->TriggerMode_Button);
    // 测试图片依次切换
    testModeButtonImages();
    testTriggerModeButtonImages();
    // 测试 Inflation/Deflation Timing 图片切换
    testInflationDeflationTimingImages();
    // 测试 InflationRatio_Button 图片切换
    testInflationRatioImages();
    // 测试反搏压按钮图片切换
    testCounterpulsationPressureImages();
    // 测试 Set 按钮图片切换
    testSetButtonImages();
    // 测试 FreezeWindow 图片切换
    testFreezeWindowImages();
    testPressureZeroingImages();
     testBottomNavigationBar_Help_ButtonImages();
     testSwitch_ButtonImages();
    testHelp_ButtonImages();
    CounterpulsationPumpImages();
    Replenish_Again_HeImages();
}

BottomNavigationBar::~BottomNavigationBar() {
    delete ui;
}

void BottomNavigationBar::refreshStyle(QWidget* w)
{
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update();
}
void BottomNavigationBar::refreshStyle1(QWidget *widget)
{
    if (!widget)
        return;

    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
    widget->update();
}
void BottomNavigationBar::testModeButtonImages()
{
    const QStringList modes = {
        "Manual_Mode_False",
        "Manual_Mode_True",
        "Automatic_Mode_False",
        "Automatic_Mode_True",
        "Mode_Unknown_False","Mode_Unknown_True"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->Mode_Button, &QPushButton::clicked,
            this, [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->Mode_Button->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->Mode_Button);
    });
}
void BottomNavigationBar::CounterpulsationPumpImages()
{
    const QStringList modes = {
        "CounterpulsationPump_Button_True",
        "CounterpulsationPump_Button_False",
        "CounterpulsationPump_Unknown_True"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->CounterpulsationPump_Button, &QPushButton::clicked,
            this, [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->CounterpulsationPump_Button->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->CounterpulsationPump_Button);
    });
}
void BottomNavigationBar::Replenish_Again_HeImages()
{
    const QStringList modes = {
        "Replenish_Again_He_Label_True",
        "Replenish_Again_He_Label_False",
        "Replenish_Again_He_Label_Stop"
    };
    auto index = std::make_shared<int>(0);

    connect(ui->Replenish_Again_Hen,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->Replenish_Again_He_Label->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->Replenish_Again_He_Label);
    });

}




void BottomNavigationBar::testTriggerModeButtonImages()
{
    const QStringList modes = {
        "Trigger_Unknown_True",
        "Trigger_Unknown_False",

        "ECG_True","ECG_False","ECG_Stop",
        "Pressure_True", "Pressure_False","Pressure_Stop",
        "Ventricular_Atrial_Fibrillation_Pacemaker_True","Ventricular_Atrial_Fibrillation_Pacemaker_False","Ventricular_Atrial_Fibrillation_Pacemaker_Stop",
        "Atrial_Pacemaker_True",       "Atrial_Pacemaker_False","Atrial_Pacemaker_Stop",
        "Interior_True","Interior_False",
        "Interior_Stop"

    };

    auto index = std::make_shared<int>(0);

    connect(ui->TriggerMode_Button, &QPushButton::clicked,
            this, [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->TriggerMode_Button->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->TriggerMode_Button);
    });
}
void BottomNavigationBar::testInflationDeflationTimingImages()
{
    const QStringList modes = {
        "Inflation_Deflation_Timing_Stop",
        "Inflation_Deflation_Timing_Unknown_True","Inflation_Deflation_Timing_Unknown_False",
        "Inflation_Deflation_Timing_False",
        "Inflation_Deflation_Timing_True"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->Inflation_Deflation_Timing_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->Inflation_Deflation_Timing_Label->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->Inflation_Deflation_Timing_Label);
    });
}
void BottomNavigationBar::testInflationRatioImages()
{
    const QStringList modes = {
        "1_1_False", "1_1_True",
        "1_2_False", "1_2_True",
        "1_3_False","1_3_True","InflationRatio_Unknown_True","InflationRatio_Unknown_False"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->InflationRatio_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->InflationRatio_Button->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->InflationRatio_Button);
    });
}
void BottomNavigationBar::testCounterpulsationPressureImages()
{
    const QStringList modes = {
        "Counterpulsation_Pressure_First_Gear_False",
        "Counterpulsation_Pressure_First_Gear_True",

        "Counterpulsation_Pressure_Second_Gear_False",
        "Counterpulsation_Pressure_Second_Gear_True",

        "Counterpulsation_Pressure_Third_Gear_False",
        "Counterpulsation_Pressure_Third_Gear_True",

        "Counterpulsation_Pressure_Fourth_Gear_False",
        "Counterpulsation_Pressure_Fourth_Gear_True",

        "Counterpulsation_Pressure_Five_Gear_False",
        "Counterpulsation_Pressure_Five_Gear_True",

        "Counterpulsation_Pressure_Sixth_Gear_False",
        "Counterpulsation_Pressure_Sixth_Gear_True",

        "Counterpulsation_Pressure_Seventh_Gear_False",
        "Counterpulsation_Pressure_Seventh_Gear_True",

        "Counterpulsation_Pressure_Eighth_Gear_False",
        "Counterpulsation_Pressure_Eighth_Gear_True",
        "Counterpulsation_Pressure_Unknown_True",
        "Counterpulsation_Pressure_Unknown_False"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->Counterpulsation_Pressure_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->Counterpulsation_Pressure_Button->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->Counterpulsation_Pressure_Button);
    });
}
void BottomNavigationBar::testSetButtonImages()
{
    const QStringList modes = {
        "Set_Button_Label_False",
        "Set_Button_Label_True"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->Set_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->Set_Button_Label->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->Set_Button_Label);
    });
}
void BottomNavigationBar::testFreezeWindowImages()
{
    const QStringList modes = {
        "FreezeWindow_Label_False",
        "FreezeWindow_Label_True"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->FreezeWindow_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->FreezeWindow_Label->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->FreezeWindow_Label);
    });
}
void BottomNavigationBar::testPressureZeroingImages()
{
    const QStringList modes = {
    "PressureZeroing_Label_False",
    "PressureZeroing_Label_True",
        "PressureZeroing_Label_Stop"
};
    auto index = std::make_shared<int>(0);
    connect(ui->PressureZeroing_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();
        ui->PressureZeroing_Label->setProperty(
            "mode",
            modes[*index]
        );
        refreshStyle(ui->PressureZeroing_Label);
    });
}
void BottomNavigationBar::testBottomNavigationBar_Help_ButtonImages()
{
    const QStringList modes = {
        "Help_Button_Label_False",
        "Help_Button_Label_True"
    };
    auto index = std::make_shared<int>(0);
    connect(ui->BottomNavigationBar_Help_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();
        ui->BottomNavigationBar_Help_Button_Label->setProperty(
            "mode",
            modes[*index]
        );
        refreshStyle(ui->BottomNavigationBar_Help_Button_Label);
    });
}
void BottomNavigationBar::testSwitch_ButtonImages(){
    const QStringList modes = {
        "Switch_Button_Label_False",
        "Switch_Button_Label_True"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->Switch_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->Switch_Button_Label->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->Switch_Button_Label);
    });
}
void BottomNavigationBar::testHelp_ButtonImages(){
    const QStringList modes = {
        "BottomNavigationBar_Help_Button_Label_False",
        "BottomNavigationBar_Help_Button_Label_True"
    };

    auto index = std::make_shared<int>(0);

    connect(ui->BottomNavigationBar_Help_Button,
            &QPushButton::clicked,
            this,
            [this, modes, index]()
    {
        *index = (*index + 1) % modes.size();

        ui->BottomNavigationBar_Help_Button_Label->setProperty(
            "mode",
            modes[*index]
        );

        refreshStyle(ui->BottomNavigationBar_Help_Button_Label);
    });
}