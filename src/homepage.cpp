//
// Created by Administrator on 2026/5/28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HomePage.h" resolved

#include "../include/homepage.h"
#include "ui_HomePage.h"


HomePage::HomePage(QWidget *parent) : QWidget(parent), ui(new Ui::HomePage) {
    ui->setupUi(this);
    topbar = new TopBar(this);
    waveformseparation = new WaveformSeparation(this);
    bottomnavigationbar = new BottomNavigationBar(this);
    bottomnavigationbar->move(0,960);
    statusbar = new StatusBar(this);
    modeselection = new ModeSelection(this);
    triggermode = new TriggerMode(this);
    inflation_Deflation_Timing = new Inflation_Deflation_Timing(this);
    inflationRatio = new InflationRatio(this);
    balloonvolume = new BalloonVolume(this);
    set = new Set(this);
    // helpinterface = new HelpInterface(this);
    alarmsystem = new AlarmSystem(this);
    messageManagement = new MessageManagement(this);
    level1alarm = new Level1Alarm(this);
    horizontalReferenceLine = new HorizontalReferenceLine(this);
    pressurezeroadjustment = new PressureZeroAdjustment(this);
    logexport = new LogExport(this);

    // horizontalReferenceLine = new HorizontalReferenceLine();
    // horizontalReferenceLine = new HorizontalReferenceLine(this);
    // horizontalReferenceLine->setGeometry(100, 100, 400, 300);
    // horizontalReferenceLine->show();
}

HomePage::~HomePage() {
    delete ui;
}
