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
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QString style = QString("QLabel{font-family:'%1';font-size:30px;"
                   "color:rgb(4, 255, 255);qproperty-alignment: 'AlignLeft | AlignVCenter';font-weight: Bold;}").arg(fontName);
    QString style1 =QString("QPushButton{border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");

    ui->AlarmText_label->setStyleSheet(style);

    QMovie *movie = new QMovie("D:/IABP/IABPUI/resource/AlarmSystem/中低级警告.gif");
        ui->Background_label->setMovie(movie);
        ui->Background_label->setScaledContents(true);
        movie->setScaledSize(ui->Background_label->size());
        movie->start();          // 开始播放动画

    ui->Help_Button->setStyleSheet("QPushButton{background-image:url(:/AlarmSystem/Frame 10090.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->Audio_Button->setStyleSheet("QPushButton{background-image:url(:/AlarmSystem/Frame 10091.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->More_Button->setStyleSheet("QPushButton{background-image:url(:/AlarmSystem/Frame 10092.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->Close_Button->setStyleSheet("QPushButton{background-image:url(:/AlarmSystem/Frame 10089.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->AlarmLevelIcon_Label->setStyleSheet("QLabel{background-image:url(:/AlarmSystem/Group 10026.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");

}

AlarmSystem::~AlarmSystem() {
    delete ui;
}