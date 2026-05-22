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
    ui->label->setProperty("class","label_Inflation_Deflation_Timing");
    ui->Finish_Button->setProperty("mode","Finish_Button_false");
    ui->InflationReduce_Button->setProperty("mode","InflationReduce_Button_false");
    ui->InflationAdd_Button->setProperty("mode","InflationAdd_Button_false");
    ui->DeflateReduce_Button->setProperty("mode","DeflateReduce_Button_false");
    ui->DeflateAdd_Button->setProperty("mode","DeflateAdd_Button_false");
    ui->InflationNum_label->setText("50");
    ui->InflationNum_label->setProperty("class","40px,colour255,255,255");
    ui->DeflateNum_label->setText("100");
    ui->DeflateNum_label->setProperty("class","40px,colour255,255,255");
    ui->ratio1_1Num_label->setProperty("class","40px,colour4,255,255,AlignCenter");
    ui->ratio1_1backdrop->setProperty("class","ratio1_1backdrop_true");
    setLetterSpacing(ui->ratio1_1Num_label,5);
    ui->ratio1_2Num_label->setProperty("class","40px,colour255,255,255,AlignCenter");
    ui->Help_Button->setProperty("class","Help_Button");
    setLetterSpacing(ui->ratio1_2Num_label,5);
    ui->ratio1_2backdrop->setProperty("class","ratio1_2backdrop_false");


}
void Inflation_Deflation_Timing::setLetterSpacing(QLabel* label,int spacing) {
    QFont font = label->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing,spacing);
    label->setFont(font);
}
Inflation_Deflation_Timing::~Inflation_Deflation_Timing() {
    delete ui;
}