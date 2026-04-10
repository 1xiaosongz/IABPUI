//
// Created by Administrator on 2026/4/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Inflation_Deflation_Timing.h" resolved

#include "../include/inflation_deflation_timing.h"
#include "ui_Inflation_Deflation_Timing.h"
#include <QFontDatabase>
/*
 * 充放气时机
 */

Inflation_Deflation_Timing::Inflation_Deflation_Timing(QWidget *parent) : QWidget(parent),
                                                                          ui(new Ui::Inflation_Deflation_Timing) {
    ui->setupUi(this);
    move(201, 594);
    setVisible(false);
    ui->label->setStyleSheet("QLabel{background-image:url(:/Inflation_Deflation_Timing/Group 10532.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font;
    font.setLetterSpacing(QFont::AbsoluteSpacing, 5);  // 间距固定为5像素

    QString style = QString("QLabel{font-family:'%1';font-size:40px;"
                   "color:rgb(4, 255, 255);qproperty-alignment: 'AlignCenter';}").arg(fontName);
    QString style2 = QString("QLabel{font-family:'%1';font-size:40px;"
                       "color:rgb(255, 255, 255);qproperty-alignment: 'AlignCenter';}").arg(fontName);
    QString style1 = QString(
                "QLabel{background-image:url(:/Inflation_Deflation_Timing/Group 10535.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    QString style3 = QString(
                "QLabel{border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    QString style4 = QString("QPushButton {border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    QString style5 = QString("QLabel{font-family:'%1';font-size:40px;"
                      "color:rgb(255, 255, 255);qproperty-alignment: 'AlignRight | AlignVCenter';}").arg(fontName);
    ui->Help_Button->setStyleSheet("QPushButton{background-image:url(:/Inflation_Deflation_Timing/Group 10259.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->Finish_Button->setStyleSheet("QPushButton{background-image:url(:/Inflation_Deflation_Timing/Group 10257.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->InflationReduce_Button->setStyleSheet("QPushButton{background-image:url(:/Inflation_Deflation_Timing/Group 10533.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->InflationAdd_Button->setStyleSheet("QPushButton{background-image:url(:/Inflation_Deflation_Timing/Group 10534.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->DeflateReduce_Button->setStyleSheet("QPushButton{background-image:url(:/Inflation_Deflation_Timing/Group 10533.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->DeflateAdd_Button->setStyleSheet("QPushButton{background-image:url(:/Inflation_Deflation_Timing/Group 10534.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->InflationNum_label->setStyleSheet(style5);
    ui->DeflateNum_label->setStyleSheet(style5);
    ui->ratio1_1backdrop->setStyleSheet(style1) ;
    ui->ratio1_1Num_label->setStyleSheet(style);
    ui->ratio1_1Num_label->setFont(font);
    ui->ratio1_1Button->setStyleSheet(style4);
    ui->ratio1_2backdrop->setStyleSheet(style1) ;
    ui->ratio1_2Num_label->setStyleSheet(style2);
    ui->ratio1_2Num_label->setFont(font);
    ui->ratio1_2Button->setStyleSheet(style4);

}

Inflation_Deflation_Timing::~Inflation_Deflation_Timing() {
    delete ui;
}