//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_WaveformSeparation.h" resolved

#include "../include/waveformseparation.h"
#include "ui_WaveformSeparation.h"
#include <QPainter>
#include <QPainterPath>

WaveformSeparation::WaveformSeparation(QWidget *parent) : QWidget(parent), ui(new Ui::WaveformSeparation) {
    ui->setupUi(this);
    move(0, 80);
    //D:/IABP/IABPUI/SourceHanSansCN-Bold.otf
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QString style = QString("QLabel{font-family:'%1';font-size:20px;"
                   "color:rgba(255, 255, 255,114);qproperty-alignment: 'AlignRight|AlignVCenter';font-weight: bold;}").arg(fontName);
    ui->ECGHigh_label->setStyleSheet(style);
    ui->ECGHigh_label->setText("120");
    ui->ECGLow_label->setStyleSheet(style);
    ui->ECGLow_label->setText("120");
    ui->ArteryHigh_label->setStyleSheet(style);
    ui->ArteryHigh_label->setText("120");
    ui->ArteryLow_label->setStyleSheet(style);
    ui->ArteryLow_label->setText("120");
    ui->BalloonPressureHigh_label->setStyleSheet(style);
    ui->BalloonPressureHigh_label->setText("120");
    ui->ECGLeadNumber_label->setStyleSheet(style);
    ui->ECGLeadNumber_label->setText("I");
    ui->BalloonPressureLow_label->setText("120");
    ui->BalloonPressureLow_label->setStyleSheet(style);


}

WaveformSeparation::~WaveformSeparation() {
    delete ui;
}
