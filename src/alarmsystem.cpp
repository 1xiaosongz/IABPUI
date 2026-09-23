//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AlarmSystem.h" resolved

#include "../include/alarmsystem.h"
#include "ui_alarmsystem.h"
#include <QFontDatabase>
#include <QMovie>
#include <QFile>
AlarmSystem::AlarmSystem(QWidget *parent) : QWidget(parent), ui(new Ui::AlarmSystem) {
    ui->setupUi(this);
    move(110, 10);
    setVisible(false);
    ui->AlarmText_Label->setText("一级警告");
    ui->AlarmText_Label->setProperty("mode","30px,colour255,255,255");
    ui->AlarmSystem_Help_Button->setProperty("mode","AlarmSystem_Help_Button");
    ui->AlarmLevelIcon_Label->setProperty("mode","AlarmLevelIcon_Advanced");
    ui->Close_Button->setProperty("mode","AlarmLevelIcon_Close_Button");


    QMovie *movie = new QMovie("../resource/AlarmSystem/Advanced_Alert.gif");
    ui->BackGround_Label->setMovie(movie);
    ui->BackGround_Label->setScaledContents(true);
    movie->setScaledSize(ui->BackGround_Label->size());
    movie->start();          // 开始播放动画
}

AlarmSystem::~AlarmSystem() {
    delete ui;
}