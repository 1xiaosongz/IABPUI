//
// Created by Administrator on 2026/5/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TopBar.h" resolved

#include "../include/topbar.h"
#include "ui_TopBar.h"

#include <QStyle>
TopBar::TopBar(QWidget *parent) : QWidget(parent), ui(new Ui::TopBar) {

    ui->setupUi(this);
    move(0,0);
    ui->Label->setProperty("mode","Label_Topbar");
    ui->AlarmBell_Button->setProperty("mode","AlarmBell_Button_False");
    ui->HeliumGasCylinderIcon_Label->setProperty("mode","HeliumGasCylinderIcon_100");
    ui->BatteryIcon_Label->setProperty("mode","BatteryIcon_100");
    ui->GasPressure_Label->setProperty("mode","20px,colour172,181,197");
    ui->BatteryRemainingCapacity_Label->setProperty("mode","20px,colour172,181,197");
    ui->Label_3->setProperty("mode","20px,colour172,181,197");
    ui->Label_6->setProperty("mode","20px,colour172,181,197");
    ui->GasPressure_Label->setText("100 psi");
    ui->BatteryRemainingCapacity_Label->setText("100%");
    ui->Pattern_Label->setText("转运");
    ui->Pattern_Label->setProperty("mode","20px,colour172,181,197");
    ui->Label_4->setProperty("mode","20px,colour172,181,197");
    ui->PatternIcon->setProperty("mode","PatternIcon_Hybrid");

    this->style()->unpolish(this);
    this->style()->polish(this);
}

TopBar::~TopBar() {
    delete ui;
}
