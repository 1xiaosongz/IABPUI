//
// Created by Administrator on 2026/3/31.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Homepage.h" resolved

#include "../include/homepage.h"
#include "ui_Homepage.h"

#include <QFontDatabase>
#include <QThread>
Homepage::Homepage(QWidget *parent) : QWidget(parent), ui(new Ui::Homepage) {
    ui->setupUi(this);
    topbar = new Topbar(this);
    waveformseparation = new WaveformSeparation(this);
    bottomnavigationbar = new BottomNavigationBar(this);
    bottomnavigationbar->move(0,960);
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

Homepage::~Homepage() {

    delete ui;
}
