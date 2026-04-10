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
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    ui->Help_Button->setStyleSheet("QPushButton {background-image: url(:/ModeSelection/Group 4638.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->label->setStyleSheet("QLabel { background-image:url(:/ModeSelection/Group 10507.png); border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Finish_Button->setStyleSheet("QPushButton {background-image: url(:/ModeSelection/Group 10257.png);border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");

    QString style = QString("QLabel{font-family:'%1';font-size:40px;"
                    "color:rgb(4, 255, 255);qproperty-alignment: 'AlignCenter';}").arg(fontName);
    QString style2 = QString("QLabel{font-family:'%1';font-size:40px;"
                       "color:rgb(255, 255, 255);qproperty-alignment: 'AlignCenter';}").arg(fontName);
    QString style1 = QString(
                "QLabel{background-image:url(:/ModeSelection/Rectangle 4580.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    QString style3 = QString(
                "QLabel{border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    ui->Automatic_backdrop->setStyleSheet(style1);
    ui->Manual_backdrop->setStyleSheet(style1);
    ui->Automatic_Button->setStyleSheet("QPushButton {border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Manual_Button->setStyleSheet("QPushButton {border: none;background-repeat: no-repeat;"
                                     " background-position: center;background-color: transparent;}");
    ui->Automatic_Label->setText("自动模式");
    ui->Manual_Label->setText("手动模式");


    ui->Automatic_Label->setStyleSheet(style);
    ui->Manual_Label->setStyleSheet(style);

}
ModeSelection::~ModeSelection() {
    delete ui;
}