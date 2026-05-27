//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BottomNavigationBar.h" resolved

#include "../include/bottomnavigationbar.h"

#include <qstyle.h>

#include "ui_BottomNavigationBar.h"
/*
 *底端
 */

BottomNavigationBar::BottomNavigationBar(QWidget *parent) : QWidget(parent), ui(new Ui::BottomNavigationBar) {
    ui->setupUi(this);
    ui->CounterpulsationPump_Button->setProperty("mode","CounterpulsationPump_Button_False");
    ui->Mode_Button->setProperty("mode","Automatic_Mode_False");
    ui->TriggerMode_Button->setProperty("mode","ECG_False");
    ui->InflationRatio_Button->setProperty("mode","1_1_False");
    ui->Inflation_Deflation_Timing_Label->setProperty("mode","Inflation_Deflation_Timing_False");
    ui->BalloonVolume_Label->setProperty("mode","BalloonVolume_False");
    ui->Inflatable_Numbers_label->setText("100");
    ui->Inflatable_Numbers_label->setProperty("mode","38px,colour4,255,255,AlignCenter");
    ui->Deflating_Number_label->setText("100");
    ui->Deflating_Number_label->setProperty("mode","38px,colour4,255,255,AlignCenter");
    ui->BalloonVolume_Number_label->setText("50.0");
    ui->BalloonVolume_Number_label->setProperty("mode","40px,colour4,255,255");
    ui->label->setProperty("mode","Label_BottomNavigationBar");
    ui->FreezeWindow_Label->setProperty("mode","FreezeWindow_Label_False");
    ui->Printer_Label->setProperty("mode","Printer_Label_False");
    ui->Help_Button_Label->setProperty("mode","Help_Button_Label_False");
    ui->Set_Button_Label->setProperty("mode","Set_Button_Label_False");
    ui->Switch_Button_Label->setProperty("mode","Switch_Button_Label_False");
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