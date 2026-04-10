//
// Created by Administrator on 2026/4/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PneumaticTesting.h" resolved

#include "../include/pneumatictesting.h"
#include "ui_PneumaticTesting.h"


PneumaticTesting::PneumaticTesting(QWidget *parent) : QWidget(parent), ui(new Ui::PneumaticTesting) {
    ui->setupUi(this);
}

PneumaticTesting::~PneumaticTesting() {
    delete ui;
}