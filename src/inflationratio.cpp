//
// Created by Administrator on 2026/4/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_InflationRatio.h" resolved

#include "../include/inflationratio.h"
#include "ui_InflationRatio.h"
#include <QFontDatabase>
/*
 * 充气比例
 */

InflationRatio::InflationRatio(QWidget *parent) : QWidget(parent), ui(new Ui::InflationRatio) {
    ui->setupUi(this);
    move(488, 704);
    setVisible(false);
    ui->label->setStyleSheet("QLabel{background-image:url(:/InflationRatio/Group 10551.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font;
    font.setLetterSpacing(QFont::AbsoluteSpacing, 5);  // 间距固定为5像素

    QString style = QString("QLabel{font-family:'%1';font-size:40px;"
                   "color:rgb(4, 255, 255);qproperty-alignment: 'AlignCenter';font-weight: bold;}").arg(fontName);
    QString style2 = QString("QLabel{font-family:'%1';font-size:40px;"
                       "color:rgb(255, 255, 255);qproperty-alignment: 'AlignCenter';font-weight: bold;}").arg(fontName);
    QString style1 = QString(
                "QLabel{background-image:url(:/InflationRatio/Rectangle 4585.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    QString style3 = QString(
                "QLabel{border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    QString style4 = QString("QPushButton {border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    QString style5 = QString("QLabel{font-family:'%1';font-size:40px;"
                      "color:rgb(255, 255, 255);qproperty-alignment: 'AlignRight | AlignVCenter';}").arg(fontName);

    ui->ratio1_1Button->setStyleSheet(style4);
    ui->ratio1_2Button->setStyleSheet(style4);
    ui->ratio1_3Button->setStyleSheet(style4);
    // ui->ratio1_1Num_label->setText("1:1");
    // ui->ratio1_2Num_label->setText("1:2");
    // ui->ratio1_3Num_label->setText("1:3");
    ui->ratio1_1Num_label->setStyleSheet(style);
    ui->ratio1_2Num_label->setStyleSheet(style2);
    ui->ratio1_3Num_label->setStyleSheet(style2);
    ui->ratio1_1Num_label->setFont(font);
    ui->ratio1_2Num_label->setFont(font);
    ui->ratio1_3Num_label->setFont(font);
    ui->Help_Button->setStyleSheet("QPushButton{background-image:url(:/InflationRatio/Group 4638.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->Finish_Button->setStyleSheet("QPushButton{background-image:url(:/InflationRatio/Group 10546.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->ratio1_1backdrop->setStyleSheet(style1);
}

InflationRatio::~InflationRatio() {
    delete ui;
}