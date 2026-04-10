//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Blank2.h" resolved

#include "../include/blank2.h"
#include "ui_Blank2.h"


Blank2::Blank2(QWidget *parent) : QWidget(parent), ui(new Ui::Blank2) {
    ui->setupUi(this);
    move(611, 118);
    setVisible(false);
    ui->label->setStyleSheet("QLabel{background-image:url(:/Blank1/Group 10402.png);border: none;background-repeat: no-repeat;"
               "background-position: center;background-color: transparent;}");
}

Blank2::~Blank2() {
    delete ui;
}