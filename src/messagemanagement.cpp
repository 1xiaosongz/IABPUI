//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MessageManagement.h" resolved

#include "../include/messagemanagement.h"
#include "ui_MessageManagement.h"
#include <QMovie>

MessageManagement::MessageManagement(QWidget *parent) : QWidget(parent), ui(new Ui::MessageManagement) {
    ui->setupUi(this);
    move(148, 98);
    setVisible(false);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->Label->setProperty("mode","MessageManagement_Label");
    ui->Widget->setProperty("mode","MessageManagement_Widget");
    ui->Close_Button->setProperty("mode","Close_Button");
}

MessageManagement::~MessageManagement() {
    delete ui;
}