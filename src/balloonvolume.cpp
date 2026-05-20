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
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QString style = QString("QLabel{font-family:'%1';font-size:40px;"
                   "color:rgb(4, 255, 255);qproperty-alignment: 'AlignRight|AlignVCenter';font-weight: Bold;}").arg(fontName);
    ui->Capacity_Label->setText("40.0");
    ui->label->setStyleSheet("QLabel{background-image:url(:/BalloonVolume/Group 10558.png);border: none;background-repeat: no-repeat;"
               "background-position: center;background-color: transparent;}");

    ui->Help_Button->setStyleSheet("QPushButton{background-image:url(:/InflationRatio/Group 4638.png);border: none;background-repeat: no-repeat;"
               "background-position: center;background-color: transparent;}");
    ui->Finish_Button->setStyleSheet("QPushButton{background-image:url(:/InflationRatio/Group 10546.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->Add_Button->setStyleSheet("QPushButton{background-image:url(:/BalloonVolume/Group 10554.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->Reduce_Button->setStyleSheet("QPushButton{background-image:url(:/BalloonVolume/Group 10555.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->Capacity_Label->setStyleSheet(style);
    ui->Capacity_Label->setText("60.0");
}

BalloonVolume::~BalloonVolume() {
    delete ui;
}