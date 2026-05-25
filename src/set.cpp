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
 ui->label->setProperty("mode","label_SET");
}

Set::~Set() {
    delete ui;
}