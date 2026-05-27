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
    ui->Label->setProperty("mode","Label_Inflation_Deflation_Timing");
    ui->Finish_Button->setProperty("mode","Finish_Button_False");
    ui->InflationReduce_Button->setProperty("mode","InflationReduce_Button_False");
    ui->InflationAdd_Button->setProperty("mode","InflationAdd_Button_False");
    ui->DeflateReduce_Button->setProperty("mode","DeflateReduce_Button_False");
    ui->DeflateAdd_Button->setProperty("mode","DeflateAdd_Button_False");
    ui->InflationNum_Label->setText("50");
    ui->InflationNum_Label->setProperty("mode","40px,colour255,255,255");
    ui->DeflateNum_Label->setText("100");
    ui->DeflateNum_Label->setProperty("mode","40px,colour255,255,255");
    ui->Ratio1_1_Num_Label->setProperty("mode","40px,colour4,255,255,AlignCenter");
    ui->Ratio1_1_Backdrop->setProperty("mode","Ratio1_1_Backdrop_True");
    setLetterSpacing(ui->Ratio1_1_Num_Label,5);
    ui->Ratio1_2_Num_Label->setProperty("mode","40px,colour255,255,255,AlignCenter");
    ui->Help_Button->setProperty("mode","Help_Button");
    setLetterSpacing(ui->Ratio1_2_Num_Label,5);
    ui->Ratio1_2_Backdrop->setProperty("mode","Ratio1_2_Backdrop_False");


}
void Inflation_Deflation_Timing::setLetterSpacing(QLabel* label,int spacing) {
    QFont font = label->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing,spacing);
    label->setFont(font);
}
Inflation_Deflation_Timing::~Inflation_Deflation_Timing() {
    delete ui;
}