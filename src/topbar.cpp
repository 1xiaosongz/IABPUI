//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Topbar.h" resolved

#include "../include/topbar.h"
#include "ui_Topbar.h"


Topbar::Topbar(QWidget *parent) : QWidget(parent), ui(new Ui::Topbar) {
    ui->setupUi(this);
    move(0,0);
    ui->label->setProperty("mode","label_Topbar");
    ui->AlarmBbell_button->setProperty("mode","AlarmBbell_button_false");
    ui->HeliumGasCylinderIcon_label->setProperty("mode","HeliumGasCylinderIcon_100");
    ui->BatteryIcon_label->setProperty("mode","BatteryIcon_100");
    ui->GasPressure_label->setProperty("mode","20px,colour172, 181, 197");
    ui->BatteryRemainingCapacity_label->setProperty("mode","20px,colour172, 181, 197");
    ui->label_3->setProperty("mode","20px,colour172, 181, 197");
    ui->label_6->setProperty("mode","20px,colour172, 181, 197");
    ui->GasPressure_label->setText("100 psi");
    ui->BatteryRemainingCapacity_label->setText("100%");

}

Topbar::~Topbar() {
    delete ui;
}