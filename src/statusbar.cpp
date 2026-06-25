//
// Created by Administrator on 2026/5/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StatusBar.h" resolved

#include "../include/statusbar.h"
#include "ui_StatusBar.h"
#include <QMovie>

StatusBar::StatusBar(QWidget *parent) : QWidget(parent), ui(new Ui::StatusBar) {
    ui->setupUi(this);
    move(1570, 80);
    ui->Heart_Rate_Label->setText("999");
    ui->Heart_Rate_Label->setProperty("mode","160px,colour22,226,58");
    ui->Label->setProperty("mode","Label_StatusBar");
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
    ui->TriggerSource->setText("触 发 源  :");
    ui->TriggerSource->setProperty("mode","20px,colour172,181,197,AlignLeft");
    ui->ThresholdValue->setText("自动阈值:");
    ui->ThresholdValue->setProperty("mode","20px,colour172,181,197,AlignLeft");
    ui->Mmhg->setText("20mmHg");
    ui->Mmhg->setProperty("mode","20px,colour172,181,197,AlignLeft");
    ui->TriggerSource_Label->setText("心房/心室起搏器");
    ui->TriggerSource_Label->setProperty("mode","20px,colour172,181,197,AlignLeft");


    QMovie *movie1 = new QMovie("../resource/StatusBar/100.gif");
    ui->HeartbeatImage->setMovie(movie1);
    ui->HeartbeatImage->setScaledContents(true);
    movie1->setScaledSize(ui->HeartbeatImage->size());
    movie1->start();          // 开始播放动画
}

StatusBar::~StatusBar() {
    delete ui;
}
