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
    ui->label->setProperty("class","InflationRatio_label");
    ui->ratio1_1backdrop->setProperty("class","ratio1_1_true");
    ui->ratio1_2backdrop->setProperty("class","ratio1_2_false");
    ui->ratio1_3backdrop->setProperty("class","ratio1_3_false");
    ui->ratio1_1Num_label->setProperty("class","40px,colour4,255,255,AlignCenter");
    ui->ratio1_2Num_label->setProperty("class","40px,colour255,255,255,AlignCenter");
    ui->ratio1_3Num_label->setProperty("class","40px,colour255,255,255,AlignCenter");
    setLetterSpacing(ui->ratio1_1Num_label,5);
    setLetterSpacing(ui->ratio1_2Num_label,5);
    setLetterSpacing(ui->ratio1_3Num_label,5);
    ui->Help_Button->setProperty("class","Help_Button");

}

InflationRatio::~InflationRatio() {
    delete ui;
}
void InflationRatio::setLetterSpacing(QLabel* label,int spacing) {
    QFont font = label->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing,spacing);
    label->setFont(font);
}