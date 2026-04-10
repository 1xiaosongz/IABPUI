//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Statusbar.h" resolved

#include "statusbar.h"
#include "ui_Statusbar.h"
#include <QFontDatabase>
#include "homepage.h"

Statusbar::Statusbar(QWidget *parent) : QWidget(parent), ui(new Ui::Statusbar) {
    ui->setupUi(this);
    move(1570, 80);
    QString a,b,c,d =homepage->Font1();
    ui->HeartRate_label->setText("999");
    ui->HeartRate_label->setStyleSheet(a);
    ui->HeartRate_label->setStyleSheet("QLabel {border: none; background-color: transparent;"
                                            "color: rgb(22, 226, 58);font-weight:normal   ;"
                                            "font-size: 160px;qproperty-alignment: 'AlignCenter';}");
    ui->mm_label->setStyleSheet("QLabel {border: none; background-color: transparent;"
                                            "font-family:SourceHanSansCN ;color: rgb(172, 181, 197); "
                                            "font-size: 20px;qproperty-alignment: 'AlignCenter';}");
    ui->mm_label->setText("20mm");
    ui->voluntarily_label->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(172, 181, 197); font-size: 20px;qproperty-alignment: 'AlignCenter';}");
    ui->voluntarily_label->setText("自动");
    ui->label_4->setText("阈   值:");
    ui->label_4->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(172, 181, 197); font-size: 20px;qproperty-alignment: 'AlignCenter';}");
    ui->label_6->setText("触发源:");
    ui->label_6->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(172, 181, 197); font-size: 20px;qproperty-alignment: 'AlignCenter';}");
    ui->TriggerSource_label->setText("压力");
    ui->TriggerSource_label->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(172, 181, 197); font-size: 20px;qproperty-alignment: 'AlignCenter';}");
    ui->HighBloodPressure_label->setText("999");
    ui->HighBloodPressure_label->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(252, 86, 78); font-size: 100px;qproperty-alignment: 'AlignCenter';}");
    ui->LowBloodPressure_label->setText("999");
    ui->LowBloodPressure_label->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(252, 86, 78); font-size: 80px;qproperty-alignment: 'AlignCenter';}");
    ui->MeanBloodPressure_label->setText("999");
    ui->MeanBloodPressure_label->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(172, 181, 197); font-size: 60px;qproperty-alignment: 'AlignCenter';}");
    ui->CounterpulsationPressure_label->setText("999");
    ui->CounterpulsationPressure_label->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(63, 184, 248); font-size: 100px;qproperty-alignment: 'AlignCenter';}");
    ui->Anti_embolismPressureAlarm_label->setText("关闭");
    ui->Anti_embolismPressureAlarm_label->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(255, 255, 255); font-size: 20px;qproperty-alignment: 'AlignCenter';}");
    ui->QuenchingFrequency_label->setText("1:1");
    ui->QuenchingFrequency_label->setStyleSheet("QLabel {border: none; background-color: transparent;font-family:SourceHanSansCN ;"
                                         "color: rgb(255, 255, 255); font-size: 20px;qproperty-alignment: 'AlignCenter';}");
}

Statusbar::~Statusbar() {
    delete ui;
}