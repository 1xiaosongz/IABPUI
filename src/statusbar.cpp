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
    ui->HeartRate_label->setText("999");
    ui->HeartRate_label->setProperty("mode","160px,colour22, 226, 58");
    ui->label->setProperty("mode","label_Statusbar");
    ui->mm_label->setProperty("mode","20px,colour172, 181, 197");
    ui->mm_label->setText("20mm");
    ui->voluntarily_label->setProperty("mode","20px,colour172, 181, 197");
    ui->voluntarily_label->setText("自动");
    ui->label_4->setText("阈   值:");
    ui->label_4->setProperty("mode","20px,colour172, 181, 197");
    ui->label_6->setText("触发源:");
    ui->label_6->setProperty("mode","20px,colour172, 181, 197");
    ui->TriggerSource_label->setText("压力");
    ui->TriggerSource_label->setProperty("mode","20px,colour172, 181, 197");
    ui->HighBloodPressure_label->setText("999");
    ui->HighBloodPressure_label->setProperty("mode","100px,colour252, 86, 78");
    ui->LowBloodPressure_label->setText("999");
    ui->LowBloodPressure_label->setProperty("mode","80px,colour252, 86, 78");
    ui->MeanBloodPressure_label->setText("999");
    ui->MeanBloodPressure_label->setProperty("mode","60px,colour172, 181, 197");
    ui->CounterpulsationPressure_label->setText("999");
    ui->CounterpulsationPressure_label->setProperty("mode","100px,colour63, 184, 248");
    ui->Anti_embolismPressureAlarm_label->setText("关闭");
    ui->Anti_embolismPressureAlarm_label->setProperty("mode","20px,colour255, 255, 255");
    ui->QuenchingFrequency_label->setText("1:1");
    ui->QuenchingFrequency_label->setProperty("mode","20px,colour255, 255, 255");

}



Statusbar::~Statusbar() {
    delete ui;
}