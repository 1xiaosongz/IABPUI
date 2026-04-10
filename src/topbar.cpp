//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Topbar.h" resolved

#include "../include/topbar.h"
#include "ui_Topbar.h"


Topbar::Topbar(QWidget *parent) : QWidget(parent), ui(new Ui::Topbar) {
    ui->setupUi(this);
    move(0,0);
    ui->AlarmBbell_button->setStyleSheet("QPushButton {background-image: url(:/Topbar/Group 9904.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->label->setStyleSheet("QLabel {background-image: url(:/Topbar/Rectangle 2846.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->HeliumGasCylinderIcon_label->setStyleSheet("QLabel {background-image: url(:/Topbar/Frame 10039.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->BatteryIcon_label->setStyleSheet("QLabel {background-image: url(:/Topbar/Group 9906.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->GasPressure_label->setStyleSheet("QLabel {border: none; background-color: transparent;qproperty-alignment: 'AlignCenter';"
                                            "font-family:SourceHanSansCN ;color: rgb(172, 181, 197); font-size: 20px;font-weight: bold;}");
    ui->BatteryRemainingCapacity_label->setStyleSheet("QLabel {border: none; background-color: transparent;qproperty-alignment: 'AlignCenter';"
                                            "font-family:SourceHanSansCN ;color: rgb(172, 181, 197); font-size: 20px;font-weight: bold;}");
    ui->GasPressure_label->setText("100 psi");
    ui->BatteryRemainingCapacity_label->setText("100%");
    ui->label_3->setStyleSheet("QLabel {border: none; background-color: transparent;qproperty-alignment: 'AlignCenter';"
                                            "font-family:SourceHanSansCN ;color: rgb(172, 181, 197); font-size: 20px;font-weight: bold;}");
    ui->label_6->setStyleSheet("QLabel {border: none; background-color: transparent;qproperty-alignment: 'AlignCenter';"
                                            "font-family:SourceHanSansCN ;color: rgb(172, 181, 197); font-size: 20px;font-weight: bold;}");

}

Topbar::~Topbar() {
    delete ui;
}