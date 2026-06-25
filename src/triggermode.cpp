//
// Created by Administrator on 2026/4/7.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TriggerMode.h" resolved

#include "../include/triggermode.h"
#include "ui_TriggerMode.h"
#include <QFontDatabase>


TriggerMode::TriggerMode(QWidget *parent) : QWidget(parent), ui(new Ui::TriggerMode) {
    ui->setupUi(this);
    move(282, 704);
    setVisible(false);
    ui->Label->setProperty("mode","Label_TriggerMode");
    ui->Help_Button->setProperty("mode","Help_Button");
    ui->ECG_Label->setText("ECG");
    setLetterSpacing(ui->ECG_Label,5);
    ui->ECG_Label->setProperty("mode","38px,colour4,255,255,AlignCenter");
    ui->ECG_Backdrop->setProperty("mode","Background_True");
    ui->Pressure_Label->setText("压力");
    setLetterSpacing(ui->Pressure_Label,5);
    ui->Pressure_Label->setProperty("mode","38px,colour255,255,255,AlignCenter");
    ui->Ventricular_AtrialFibrillationPacemaker_Label->setText("心室/房颤<br>起搏器");
    ui->Ventricular_AtrialFibrillationPacemaker_Label->setProperty("mode","38px,colour255,255,255,AlignCenter");
    ui->AtrialPacemaker_Label->setText("心房<br>起搏器");
    setLetterSpacing(ui->AtrialPacemaker_Label,5);
    ui->AtrialPacemaker_Label->setProperty("mode","38px,colour255,255,255,AlignCenter");
    ui->Inside_Label->setText("内部");
    setLetterSpacing(ui->Inside_Label,5);
    ui->Inside_Label->setProperty("mode","38px,colour255,255,255,AlignCenter");
    // ui->Finish_Button->setProperty("mode","Finish_Button_False");
}

void TriggerMode::setLetterSpacing(QLabel* label,int spacing) {
    QFont font = label->font();
    font.setLetterSpacing(QFont::AbsoluteSpacing,spacing);
    label->setFont(font);
}
TriggerMode::~TriggerMode() {
    delete ui;
}
