//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Homepage.h" resolved

#include "../include/homepage.h"
#include "ui_Homepage.h"
#include <QFontDatabase>

Homepage::Homepage(QWidget *parent) : QWidget(parent), ui(new Ui::Homepage) {
    ui->setupUi(this);
    topbar = new Topbar(this);
    waveformseparation = new WaveformSeparation(this);
    bottomnavigationbar = new BottomNavigationBar(this);
    statusbar = new Statusbar(this);
    modeselection = new ModeSelection(this);
    triggermode = new TriggerMode(this);
    inflation_Deflation_Timing = new Inflation_Deflation_Timing(this);
    inflationRatio = new InflationRatio(this);
    balloonvolume = new BalloonVolume(this);
    set = new Set(this);
    blank1 = new Blank1(this);
    blank2 = new Blank2(this);
    alarmsystem = new AlarmSystem(this);
    messageManagement = new MessageManagement(this);
    level1alarm = new Level1Alarm(this);
}
QString Homepage::Font1() {
    int fontId =QFontDatabase::addApplicationFont(QStringLiteral("D:/IABP/IABPUI/SourceHanSansCN-Bold.otf"));
    QString fontName =QFontDatabase::applicationFontFamilies(fontId).at(0);
    QString style = QString("QLabel{font-family:'%1';}").arg(fontName);
    QString style2 = QString("QLabel{font-family:'%1';font-size:40px;"
                       "color:rgb(255, 255, 255);qproperty-alignment: 'AlignCenter';}").arg(fontName);
    QString style1 = QString(
                "QLabel{background-image:url(:/ModeSelection/Rectangle 4580.png);border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    QString style3 = QString(
                "QLabel{border: none;background-repeat: no-repeat;"
                "background-position: center;background-color: transparent;}");
    return style ,style1,style2,style3;
}
Homepage::~Homepage() {
    delete ui;
}