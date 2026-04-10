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
    ui->label->setStyleSheet("QLabel{background-image:url(:/TriggerMode/Group 10516.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font;
    font.setLetterSpacing(QFont::AbsoluteSpacing, 5);  // 间距固定为5像素

    QString style = QString("QLabel{font-family:'%1';font-size:40px;"
                   "color:rgb(4, 255, 255);qproperty-alignment: 'AlignCenter';}").arg(fontName);
    QString style2 = QString("QLabel{font-family:'%1';font-size:40px;"
                       "color:rgb(255, 255, 255);qproperty-alignment: 'AlignCenter';}").arg(fontName);
    QString style1 = QString(
                "QLabel{background-image:url(:/TriggerMode/Rectangle 4581.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    QString style3 = QString(
                "QLabel{border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    QString style4 = QString("QPushButton {border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Finish_Button->setStyleSheet("QPushButton {background-image: url(:/TriggerMode/Group 10517.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Help_Button->setStyleSheet("QPushButton {background-image: url(:/TriggerMode/Group 4638.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->ECG_Label->setText("ECG");
    ui->ECG_Label->setFont(font);
    ui->ECG_Label->setStyleSheet(style);
    ui->ECG_backdrop->setStyleSheet(style1);
    ui->ECG_Button->setStyleSheet(style4);
    ui->Pressure_Label->setText("压力");
    ui->Pressure_Label->setFont(font);
    ui->Pressure_Label->setStyleSheet(style2);
    ui->Pressure_backdrop->setStyleSheet(style3);
    ui->Pressure_Button->setStyleSheet(style4);
    ui->Ventricular_AtrialFibrillationPacemaker_Label->setText("心室/房颤<br>起搏器");
    // ui->Ventricular_AtrialFibrillationPacemaker_Label->setFont(font);
    ui->Ventricular_AtrialFibrillationPacemaker_Label->setStyleSheet(style2);
    ui->Ventricular_AtrialFibrillationPacemaker_backdrop->setStyleSheet(style1);
    ui->Ventricular_AtrialFibrillationPacemaker_Button->setStyleSheet(style4);
    ui->AtrialPacemaker_Label->setText("心房<br>起搏器");
    ui->AtrialPacemaker_Label->setFont(font);
    ui->AtrialPacemaker_Label->setStyleSheet(style2);
    ui->AtrialPacemaker_backdrop->setStyleSheet(style1);
    ui->AtrialPacemaker_Button->setStyleSheet(style4);
    ui->Inside_Label->setText("内部");
    ui->Inside_Label->setFont(font);
    ui->Inside_Label->setStyleSheet(style2);
    ui->Inside_backdrop->setStyleSheet(style3);
    ui->Inside_Button->setStyleSheet(style4);

}

TriggerMode::~TriggerMode() {
    delete ui;
}