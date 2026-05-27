//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Topbar.h" resolved

#include "../include/topbar.h"
#include "ui_Topbar.h"


Topbar::Topbar(QWidget *parent) : QWidget(parent), ui(new Ui::Topbar) {
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

}

Topbar::~Topbar() {
    delete ui;
}