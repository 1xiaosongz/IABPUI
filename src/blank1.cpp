//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Blank1.h" resolved

#include "../include/blank1.h"
#include "ui_Blank1.h"


Blank1::Blank1(QWidget *parent) : QWidget(parent), ui(new Ui::Blank1) {
    ui->setupUi(this);
    move(520, 118);
    setVisible(false);
    ui->label->setProperty("mode","label_Blank1");
}

Blank1::~Blank1() {
    delete ui;
}