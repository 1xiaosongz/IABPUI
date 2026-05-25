//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_WaveformSeparation.h" resolved

#include "../include/waveformseparation.h"
#include "ui_WaveformSeparation.h"


WaveformSeparation::WaveformSeparation(QWidget *parent) : QWidget(parent), ui(new Ui::WaveformSeparation) {
    ui->setupUi(this);
    move(0, 80);

    ui->ECGHigh_label->setText("120");
    ui->ECGHigh_label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ECGHigh_label);
    ui->ECGLow_label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ECGLow_label);
    ui->ECGLow_label->setText("120");
    ui->ArteryHigh_label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ArteryHigh_label);
    ui->ArteryHigh_label->setText("120");
    ui->ArteryLow_label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ArteryLow_label);
    ui->ArteryLow_label->setText("120");
    ui->BalloonPressureHigh_label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->BalloonPressureHigh_label);
    ui->BalloonPressureHigh_label->setText("120");
    ui->ECGLeadNumber_label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->ECGLeadNumber_label);
    ui->ECGLeadNumber_label->setText("I");
    ui->BalloonPressureLow_label->setText("120");
    ui->BalloonPressureLow_label->setProperty("mode","20px,colour255,255,255,114");
    refreshStyle(ui->BalloonPressureLow_label);


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