//
// Created by Administrator on 2026/9/3.
//

// You may need to build the project (run Qt uic code generator) to get "ui_patient_information.h" resolved

#include "../include/patient_information.h"
#include "ui_patient_information.h"


patient_information::patient_information(QWidget *parent) : QWidget(parent), ui(new Ui::patient_information) {
    ui->setupUi(this);
}

patient_information::~patient_information() {
    delete ui;
}
