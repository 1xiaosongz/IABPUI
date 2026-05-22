//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Topbar.h" resolved

#include "../include/topbar.h"
#include "ui_Topbar.h"


Topbar::Topbar(QWidget *parent) : QWidget(parent), ui(new Ui::Topbar) {
    ui->setupUi(this);
    move(0,0);
    ui->label->setProperty("class","label_Topbar");
    ui->AlarmBbell_button->setProperty("class","AlarmBbell_button");
    ui->HeliumGasCylinderIcon_label->setProperty("class","HeliumGasCylinderIcon_label");
    ui->BatteryIcon_label->setProperty("class","BatteryIcon_label");
    ui->GasPressure_label->setProperty("class","20px,colour172, 181, 197");
    ui->BatteryRemainingCapacity_label->setProperty("class","20px,colour172, 181, 197");
    ui->label_3->setProperty("class","20px,colour172, 181, 197");
    ui->label_6->setProperty("class","20px,colour172, 181, 197");
    ui->GasPressure_label->setText("100 psi");
    ui->BatteryRemainingCapacity_label->setText("100%");

}

Topbar::~Topbar() {
    delete ui;
}