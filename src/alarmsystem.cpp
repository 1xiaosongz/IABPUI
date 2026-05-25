//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AlarmSystem.h" resolved

#include "../include/alarmsystem.h"
#include "ui_AlarmSystem.h"
#include <QFontDatabase>
#include <QMovie>
#include <QFile>
AlarmSystem::AlarmSystem(QWidget *parent) : QWidget(parent), ui(new Ui::AlarmSystem) {
    ui->setupUi(this);
    move(185, 10);
    setVisible(false);

    ui->AlarmText_label->setProperty("mode","30px,colour255,255,255");
    ui->Help_Button->setProperty("mode","Help_Button");
    ui->AlarmLevelIcon_Label->setProperty("mode","AlarmLevelIcon_advanced");

    QMovie *movie = new QMovie("D:/IABP/IABPUI/resource/AlarmSystem/中低级警告.gif");
    ui->Background_label->setMovie(movie);
    ui->Background_label->setScaledContents(true);
    movie->setScaledSize(ui->Background_label->size());
    movie->start();          // 开始播放动画
}

AlarmSystem::~AlarmSystem() {
    delete ui;
}