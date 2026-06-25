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
    ui->Label->setProperty("mode","InflationRatio_Label");
    ui->Ratio1_1_Backdrop->setProperty("mode","Ratio_True");
    ui->Ratio1_2_Backdrop->setProperty("mode","Ratio_False");
    ui->Ratio1_3_Backdrop->setProperty("mode","Ratio_False");
    ui->Ratio1_1_Num_Label->setProperty("mode","40px,colour4,255,255,AlignCenter");
    ui->Ratio1_2_Num_Label->setProperty("mode","40px,colour255,255,255,AlignCenter");
    ui->Ratio1_3_Num_Label->setProperty("mode","40px,colour255,255,255,AlignCenter");
    setLetterSpacing(ui->Ratio1_1_Num_Label,5);
    setLetterSpacing(ui->Ratio1_2_Num_Label,5);
    setLetterSpacing(ui->Ratio1_3_Num_Label,5);
    ui->Help_Button->setProperty("mode","Help_Button");
    // ui->Finish_Button->setProperty("mode","Finish_Button_False");
}

InflationRatio::~InflationRatio() {
    delete ui;
}
void InflationRatio::setLetterSpacing(QLabel* label,int spacing) {
    QFont font = label->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing,spacing);
    label->setFont(font);
}