//
// Created by Administrator on 2026/4/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Level1Alarm.h" resolved

#include "../include/level1alarm.h"
#include "ui_Level1Alarm.h"

#include <QFontDatabase>
Level1Alarm::Level1Alarm(QWidget *parent) : QFrame(parent), ui(new Ui::Level1Alarm) {
    ui->setupUi(this);

    // setVisible(false);
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QString style = QString("QLabel{font-family:'%1';font-size:30px;"
                   "color:rgb(4, 255, 255);qproperty-alignment: 'AlignLeft | AlignVCenter';font-weight: Bold;}").arg(fontName);
    QString style1 =QString("QPushButton{border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->AlarmText_label->setText("一级告警提示一级告警提示一级告警提示");
    ui->AlarmText_label->setStyleSheet(style);
    ui->Help_Button->setStyleSheet(style1);
    ui->Level1_label->setStyleSheet("QLabel{background-image:url(:/Blank1/Group 10571.png);border: none;background-repeat: no-repeat;"
               "background-position: center;background-color: transparent;}");
}

Level1Alarm::~Level1Alarm() {
    delete ui;
}