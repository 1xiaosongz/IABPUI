//
// Created by Administrator on 2026/4/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Inflation_Deflation_Timing.h" resolved

#include "../include/inflation_deflation_timing.h"
#include "ui_Inflation_Deflation_Timing.h"
#include <QFontDatabase>
#include <qstyle.h>
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
    ui->InflationNum_Label->setText("50");
    ui->InflationNum_Label->setProperty("mode","40px,colour255,255,255");
    ui->DeflateNum_Label->setText("6");
    ui->DeflateNum_Label->setProperty("mode","40px,colour255,255,255");
    ui->InflationReduce_Button->setProperty("mode", "Reduce");
    ui->DeflateReduce_Button->setProperty("mode", "Reduce");
    ui->InflationAdd_Button->setProperty("mode", "Add");
    ui->DeflateAdd_Button->setProperty("mode", "Add");
    ui->Help_Button->setProperty("mode","Help_Button");

}
void Inflation_Deflation_Timing::setLetterSpacing(QLabel* label,int spacing) {
    QFont font = label->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing,spacing);
    label->setFont(font);
}
Inflation_Deflation_Timing::~Inflation_Deflation_Timing() {
    delete ui;
}






