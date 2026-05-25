//
// Created by Administrator on 2026/4/1.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ModeSelection.h" resolved

#include "../include/modeselection.h"
#include "ui_ModeSelection.h"
#include <QFontDatabase>
/*
 * 模式选择
 */

ModeSelection::ModeSelection(QWidget *parent) : QWidget(parent), ui(new Ui::ModeSelection) {
    ui->setupUi(this);
    move(228, 704);
    setVisible(false);
    ui->Help_Button->setProperty("mode","Help_Button");
    ui->label->setProperty("mode","ModeSelection_label");
    ui->Automatic_Label->setText("自动模式");
    ui->Manual_Label->setText("手动模式");
    ui->Automatic_Label->setProperty("mode","40px,colour4,255,255,AlignCenter");
    ui->Manual_Label->setProperty("mode","40px,colour255,255,255,AlignCenter");
    ui->Automatic_backdrop->setProperty("mode","Automatic_backdrop_true");
    ui->Manual_backdrop->setProperty("mode","Manual_backdrop_false");
    ui->Finish_Button->setProperty("mode","Finish_Button_false");
}
ModeSelection::~ModeSelection() {
    delete ui;
}