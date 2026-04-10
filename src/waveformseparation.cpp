//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_WaveformSeparation.h" resolved

#include "../include/waveformseparation.h"
#include "ui_WaveformSeparation.h"


WaveformSeparation::WaveformSeparation(QWidget *parent) : QWidget(parent), ui(new Ui::WaveformSeparation) {
    ui->setupUi(this);
    move(0, 80);
}

WaveformSeparation::~WaveformSeparation() {
    delete ui;
}