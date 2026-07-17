//
// Created by Administrator on 2026/6/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HelpInterface.h" resolved

#include "../include/helpinterface.h"
#include "ui_HelpInterface.h"


HelpInterface::HelpInterface(QWidget *parent) : QWidget(parent), ui(new Ui::HelpInterface) {
    ui->setupUi(this);
    move(1157, 100);
    // setVisible(false);
    ui->HelpInterfaceLabel->setProperty("mode","HelpInterfaceLabel");
    ui->Title_Label->setText("血压传感器可能异常 ");
    ui->Title_Label->setProperty("mode","30px,colour255,255,255");

    ui->Content_Label->setText("当传感 器或者传感器电缆中任意导线断开或与其他导线短路会引起不正常的状态时，或当传感器的连接线被拔出时触发。传感器输出端子之间的短路检测不做要求。");
    ui->Content_Label->setWordWrap(true);
    ui->Content_Label->setProperty("mode","20px,colour172,181,197,AlignTop");
}

HelpInterface::~HelpInterface() {
    delete ui;
}
