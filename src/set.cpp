//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Set.h" resolved

#include "../include/set.h"
#include "ui_Set.h"


Set::Set(QWidget *parent) : QWidget(parent), ui(new Ui::Set) {
    ui->setupUi(this);
    move( 808, 390);
    setVisible(false);
    ui->label->setStyleSheet("QLabel{background-image:url(:/Set/Group 10402.png);border: none;background-repeat: no-repeat;"
               "background-position: center;background-color: transparent;}");
}

Set::~Set() {
    delete ui;
}