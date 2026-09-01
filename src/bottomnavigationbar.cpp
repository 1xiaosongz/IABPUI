//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BottomNavigationBar.h" resolved

#include "../include/bottomnavigationbar.h"

#include <qstyle.h>

#include <QGraphicsDropShadowEffect>

#include "ui_BottomNavigationBar.h"
/*
 *底端
 */

BottomNavigationBar::BottomNavigationBar(QWidget *parent) : QWidget(parent), ui(new Ui::BottomNavigationBar) {
    ui->setupUi(this);
    ui->CounterpulsationPump_Button->setProperty("mode","CounterpulsationPump_Button_False");
    ui->Mode_Button->setProperty("mode","Automatic_Mode_False");
    ui->TriggerMode_Button->setProperty("mode","Pressure_Stop");
    ui->InflationRatio_Button->setProperty("mode","1_1_False");
    ui->Inflation_Deflation_Timing_Label->setProperty("mode","Inflation_Deflation_Timing_False");
    ui->BalloonVolume_Label->setProperty("mode","BalloonVolume_False");
    ui->Inflatable_Numbers_label->setText("100");
    ui->Inflatable_Numbers_label->setProperty("mode","38px,colour4,255,255");
    ui->Deflating_Number_label->setText("100");
    ui->Deflating_Number_label->setProperty("mode","38px,colour4,255,255");
    ui->BalloonVolume_Number_label->setText("50");
    ui->BalloonVolume_Number_label->setProperty("mode","40px,colour255,255,255");
    ui->BalloonPercentage->setText("90");
    ui->BalloonPercentage->setProperty("mode","40px,colour4,255,255");
    ui->Label->setProperty("mode","Label_BottomNavigationBar");
    ui->FreezeWindow_Label->setProperty("mode","FreezeWindow_Label_False"); 
    ui->PressureZeroing_Label->setProperty("mode","PressureZeroing_Label_False");
    ui->Help_Button_Label->setProperty("mode","Help_Button_Label_False");
    ui->Set_Button_Label->setProperty("mode","Set_Button_Label_False");
    ui->Switch_Button_Label->setProperty("mode","Switch_Button_Label_False");
    ui->Bottom_BalloonVolume_Label->setProperty("mode","18px,colour172,181,197");
    ui->Bottom_BalloonVolume_Label->setText("40cc");
    ui->label->setProperty("mode","18px,colour172,181,197");
    ui->label_2->setProperty("mode","18px,colour172,181,197");
    ui->label_3->setProperty("mode","18px,colour172,181,197");
    ui->label_4->setProperty("mode","18px,colour172,181,197");
    ui->label_5->setProperty("mode","18px,colour172,181,197");
    ui->label_6->setProperty("mode","18px,colour172,181,197");
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
    auto balloonVolumeShadow = new QGraphicsDropShadowEffect(this);
    balloonVolumeShadow->setOffset(0, 4);
    balloonVolumeShadow->setColor(QColor(0, 0, 0, 64));
    ui->BalloonVolume_Number_label->setGraphicsEffect(balloonVolumeShadow);
    auto balloonVolumeShadow2 = new QGraphicsDropShadowEffect(this);
    balloonVolumeShadow2->setOffset(0, 4);
    balloonVolumeShadow2->setColor(QColor(0, 0, 0, 64));
    ui->BalloonPercentage->setGraphicsEffect(balloonVolumeShadow2);




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
