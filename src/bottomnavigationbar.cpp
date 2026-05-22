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
    ui->CounterpulsationPump_Button->setProperty("class","false");
    ui->Mode_Button->setProperty("mode","automatic_mode_false");
    ui->TriggerMode_Button->setProperty("mode","ECG_false");
    ui->InflationRatio_Button->setProperty("mode","1_1_false");
    ui->Inflation_Deflation_Timing_Label->setProperty("mode","Inflation_Deflation_Timing_false");
    ui->BalloonVolume_Label->setProperty("mode","BalloonVolume_false");
    ui->Inflatable_Numbers_label->setText("100");
    ui->Inflatable_Numbers_label->setProperty("class","38px,colour255,255,255");
    ui->Deflating_Number_label->setText("100");
    ui->Deflating_Number_label->setProperty("class","38px,colour4,255,255");
    ui->BalloonVolume_Number_label->setText("50.0");
    ui->BalloonVolume_Number_label->setProperty("class","40px,colour4,255,255");
    ui->label->setProperty("class","label_BottomNavigationBar");
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