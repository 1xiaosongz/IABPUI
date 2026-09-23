//
// Created by Administrator on 2026/4/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Level1Alarm.h" resolved

#include "level1alarm.h"
#include "ui_level1alarm.h"

#include <QFontDatabase>
Level1Alarm::Level1Alarm(QWidget *parent) : QFrame(parent), ui(new Ui::Level1Alarm) {
    ui->setupUi(this);
    // move(110, 10);
    // setVisible(false);
    ui->AlarmText_Label->setText("一级告警提示一级告警提示一级告警提示");
    ui->AlarmText_Label->setProperty("mode","30px,colour255,255,255");
    ui->Help_Button->setProperty("mode","Help_Button");
    ui->Level1_Label->setProperty("mode","Level1_Advanced");

}

Level1Alarm::~Level1Alarm() {
    delete ui;
}