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
    ui->Capacity_Label->setText("40");
    ui->Label->setProperty("mode","Label_BalloonVolume");
    ui->Help_Button->setProperty("mode","Help_Button");
    ui->Capacity_Label->setProperty("mode","30px,colour172,181,197,AlignRight");
    ui->Label_2->setText("型号:");
    ui->Model_Label->setText("40cc");
    ui->Label_2->setProperty("mode","20px,colour216,225,234");
    ui->Model_Label->setProperty("mode","20px,colour216,225,234");
    ui->CapacityRatio_Label->setText("100");
    ui->CapacityRatio_Label->setProperty("mode","40px,colour255,255,255,AlignCenter");

}

BalloonVolume::~BalloonVolume() {
    delete ui;
}