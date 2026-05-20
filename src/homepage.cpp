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
    statusbar = new Statusbar(this);
    sendingthread = new SendingThread();
    sendingthread->moveToThread(&m_sendingthread);
    connect(this,&Homepage::startWork,sendingthread,&SendingThread::doWork);
    connect(sendingthread, &SendingThread::workFinished, this, &Homepage::onWorkFinished);
    connect(&m_sendingthread, &QThread::finished, sendingthread, &QObject::deleteLater);
    m_sendingthread.start();
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
    m_sendingthread.quit();
    m_sendingthread.wait();
    delete ui;
}
void Homepage::onWorkFinished(int result)
{
    qDebug() << "计算完成，结果:" << result;
    // 在这里可以更新 UI，例如 label->setText(QString::number(result));
}

void Homepage::onProgressUpdated(int value)
{
    qDebug() << "进度:" << value;
    // 在这里可以更新进度条
}