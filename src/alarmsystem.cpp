//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AlarmSystem.h" resolved

#include "../include/alarmsystem.h"
#include "ui_AlarmSystem.h"
#include <QFontDatabase>

AlarmSystem::AlarmSystem(QWidget *parent) : QWidget(parent), ui(new Ui::AlarmSystem) {
    ui->setupUi(this);
    move(185, 10);
    // setVisible(false);
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QString style = QString("QLabel{font-family:'%1';font-size:30px;"
                   "color:rgb(4, 255, 255);qproperty-alignment: 'AlignLeft | AlignVCenter';font-weight: Bold;}").arg(fontName);
    QString style1 =QString("QPushButton{border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");

    ui->AlarmText_label->setStyleSheet(style);
    ui->Background_label->setStyleSheet("QLabel{background-image:url(:/AlarmSystem/Group 10566.png);border: none;background-repeat: no-repeat;"
               "background-position: center;background-color: transparent;}");


    ui->Help_Button->setStyleSheet(style1);
    ui->Audio_Button->setStyleSheet(style1);
    ui->More_Button->setStyleSheet(style1);
    ui->Close_Button->setStyleSheet(style1);


}

AlarmSystem::~AlarmSystem() {
    delete ui;
}