//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_WaveformSeparation.h" resolved

#include "../include/waveformseparation.h"
#include "ui_WaveformSeparation.h"


WaveformSeparation::WaveformSeparation(QWidget *parent) : QWidget(parent), ui(new Ui::WaveformSeparation) {
    ui->setupUi(this);
    move(0, 80);

    ui->ECGHigh_Label->setText("120");
    ui->ECGHigh_Label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ECGHigh_Label);
    ui->ECGLow_Label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ECGLow_Label);
    ui->ECGLow_Label->setText("120");
    ui->ArteryHigh_Label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ArteryHigh_Label);
    ui->ArteryHigh_Label->setText("120");
    ui->ArteryLow_Label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ArteryLow_Label);
    ui->ArteryLow_Label->setText("120");
    ui->BalloonPressureHigh_Label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->BalloonPressureHigh_Label);
    ui->BalloonPressureHigh_Label->setText("120");
    ui->ECGLeadNumber_Label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ECGLeadNumber_Label);
    ui->ECGLeadNumber_Label->setText("I");
    ui->BalloonPressureLow_Label->setText("120");
    ui->BalloonPressureLow_Label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->BalloonPressureLow_Label);
    ui->Dial_Button->setProperty("mode","Dial_Button");
    refreshStyle(ui->Dial_Button);
    ui->PressureSource->setText("压力源:");
    ui->SensingElement->setText("传感器");
    ui->labelx->setText("-");
    ui->Zeroing_Completed->setText("调零完成");
    ui->PressureSource->setProperty("mode","24px,colour252,86,78");
    ui->SensingElement->setProperty("mode","24px,colour252,86,78");
    ui->labelx->setProperty("mode","24px,colour252,86,78");
    ui->Zeroing_Completed->setProperty("mode","24px,colour252,86,78");
    refreshStyle(ui->PressureSource);
    refreshStyle(ui->SensingElement);
    refreshStyle(ui->labelx);
    refreshStyle(ui->Zeroing_Completed);
}

WaveformSeparation::~WaveformSeparation() {
    delete ui;
}
void WaveformSeparation::refreshStyle(QWidget* w)
{
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update();
}