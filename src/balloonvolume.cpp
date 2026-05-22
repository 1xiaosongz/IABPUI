//
// Created by Administrator on 2026/4/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BalloonVolume.h" resolved

#include "../include/balloonvolume.h"
#include "ui_BalloonVolume.h"
#include <QFontDatabase>
/*
 * 球囊压力
 */

BalloonVolume::BalloonVolume(QWidget *parent) : QWidget(parent), ui(new Ui::BalloonVolume) {
    ui->setupUi(this);
    move(611, 659);

    setVisible(false);
    ui->Capacity_Label->setText("40.0");
    ui->label->setProperty("class","label_BalloonVolume");
    ui->Help_Button->setProperty("class","Help_Button");
    ui->Capacity_Label->setProperty("class","40px,colour4,255,255");
    ui->Finish_Button->setProperty("mode","Finish_Button_false");
    ui->Add_Button->setProperty("mode","Add_Button_false");
    ui->Reduce_Button->setProperty("mode","Reduce_Button_false");
    ui->label_2->setText("型号:");
    ui->model_label->setText("40cc");
    ui->label_2->setProperty("class","20px,colour216,225,234");
    ui->model_label->setProperty("class","20px,colour216,225,234");
}

BalloonVolume::~BalloonVolume() {
    delete ui;
}