//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Statusbar.h" resolved

#include "statusbar.h"
#include "ui_Statusbar.h"
#include <QFontDatabase>


Statusbar::Statusbar(QWidget *parent) : QWidget(parent), ui(new Ui::Statusbar) {
    ui->setupUi(this);
    move(1570, 80);
    ui->Heart_Rate_Label->setText("999");
    ui->Heart_Rate_Label->setProperty("mode","160px,colour22,226,58");
    ui->Label->setProperty("mode","Label_Statusbar");
    ui->Mm_Label->setProperty("mode","20px,colour172,181,197");
    ui->Mm_Label->setText("20mm");
    ui->Voluntarily_Label->setProperty("mode","20px,colour172,181,197");
    ui->Voluntarily_Label->setText("自动");
    ui->Label_4->setText("阈   值:");
    ui->Label_4->setProperty("mode","20px,colour172,181,197");
    ui->Label_6->setText("触发源:");
    ui->Label_6->setProperty("mode","20px,colour172,181,197");
    ui->TriggerSource_Label->setText("压力");
    ui->TriggerSource_Label->setProperty("mode","20px,colour172,181,197");
    ui->HighBloodPressure_Label->setText("999");
    ui->HighBloodPressure_Label->setProperty("mode","100px,colour252,86,78");
    ui->LowBloodPressure_Label->setText("999");
    ui->LowBloodPressure_Label->setProperty("mode","80px,colour252,86,78");
    ui->MeanBloodPressure_Label->setText("999");
    ui->MeanBloodPressure_Label->setProperty("mode","60px,colour172,181,197");
    ui->CounterpulsationPressure_Label->setText("999");
    ui->CounterpulsationPressure_Label->setProperty("mode","100px,colour63,184,248");
    ui->Anti_embolismPressureAlarm_Label->setText("关闭");
    ui->Anti_embolismPressureAlarm_Label->setProperty("mode","20px,colour255,255,255");
    ui->QuenchingFrequency_Label->setText("1:1");
    ui->QuenchingFrequency_Label->setProperty("mode","20px,colour255,255,255");

}



Statusbar::~Statusbar() {
    delete ui;
}