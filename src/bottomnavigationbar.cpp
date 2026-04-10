//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_BottomNavigationBar.h" resolved

#include "../include/bottomnavigationbar.h"
#include "ui_BottomNavigationBar.h"
/*
 *底端
 */

BottomNavigationBar::BottomNavigationBar(QWidget *parent) : QWidget(parent), ui(new Ui::BottomNavigationBar) {
    ui->setupUi(this);

    move(0, 960);
    ui->CounterpulsationPump_Button->setStyleSheet("QPushButton {background-image: url(:/BottomNavigationBar/Group 10174.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Mode_Button->setStyleSheet("QPushButton {background-image: url(:/BottomNavigationBar/Group 10399.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->TriggerMode_Button->setStyleSheet("QPushButton {background-image: url(:/BottomNavigationBar/Group 10376.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Inflation_Deflation_Timing_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Group 10400.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->InflationRatio_Button->setStyleSheet("QPushButton {background-image: url(:/BottomNavigationBar/Group 10401.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->BalloonVolume_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Group 10341.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Blank_1_Button_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Frame 10102.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Blank_2_Button_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Frame 10102.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Blank_3_Button_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Frame 10102.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Help_Button_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Frame 10103.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Set_Button_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Frame 10104.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Switch_Button_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Frame 10105.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Blank_1_Button->setStyleSheet("QPushButton{  border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Blank_2_Button->setStyleSheet("QPushButton{  border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Blank_3_Button->setStyleSheet("QPushButton{  border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Help_Button->setStyleSheet("QPushButton{  border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Set_Button->setStyleSheet("QPushButton{  border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Switch_Button->setStyleSheet("QPushButton{  border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Inflation_Deflation_Timing_Button->setStyleSheet("QPushButton{  border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->BalloonVolume_Button->setStyleSheet("QPushButton{  border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Inflatable_Numbers_label->setText("100");
    ui->Inflatable_Numbers_label->setStyleSheet("QLabel {border: none; background-color: transparent;qproperty-alignment: 'AlignRight | AlignVCenter';"
                                            "font-family:SourceHanSansCN ;color: rgb(04, 255, 255); font-size: 38px;font-weight: bold;}");
    ui->Deflating_Number_label->setText("100");
    ui->Deflating_Number_label->setStyleSheet("QLabel {border: none; background-color: transparent;qproperty-alignment: 'AlignRight | AlignVCenter';"
                                            "font-family:SourceHanSansCN ;color: rgb(04, 255, 255); font-size: 38px;font-weight: bold;}");
    ui->BalloonVolume_Number_label->setText("10.0");
    ui->BalloonVolume_Number_label->setStyleSheet("QLabel {border: none; background-color: transparent;qproperty-alignment: 'AlignHCenter | AlignVCenter';"
                                            "font-family:SourceHanSansCN ;color: rgb(04, 255, 255); font-size: 40px;font-weight: bold;}");
    ui->label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Mask group.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
}

BottomNavigationBar::~BottomNavigationBar() {
    delete ui;
}
void BottomNavigationBar::on_Set_Button_clicked() {
    if(set1){
        ui->Set_Button_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Frame 10104.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}" );
        set1 = false;
    }else{
        ui->Set_Button_Label->setStyleSheet("QLabel { background-image:url(:/BottomNavigationBar/Group 9809.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
        set1 = true;
    }
}