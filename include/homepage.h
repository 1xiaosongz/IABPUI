//
// Created by Administrator on 2026/3/31.
//

#ifndef IABPUI_HOMEPAGE_H
#define IABPUI_HOMEPAGE_H

#include <QWidget>
#include "QMainWindow"
#include "topbar.h"
#include "waveformseparation.h"
#include "statusbar.h"
#include "bottomnavigationbar.h"
#include "modeselection.h"
#include "triggermode.h"
#include "inflation_deflation_timing.h"
#include "inflationratio.h"
#include "balloonvolume.h"
#include "set.h"
#include "blank1.h"
#include "blank2.h"
#include "alarmsystem.h"
#include "messagemanagement.h"
#include "level1alarm.h"
#include "readfile.h"
#include <QObject>
#include "sendingthread.h"

#include <QThread>
QT_BEGIN_NAMESPACE

namespace Ui {
    class Homepage;

}

QT_END_NAMESPACE

class Homepage : public QWidget {
    Q_OBJECT

public:
    explicit Homepage(QWidget *parent = nullptr);

    ~Homepage() override;

private:
    Topbar * topbar;
    WaveformSeparation * waveformseparation;
    BottomNavigationBar * bottomnavigationbar;
    Statusbar * statusbar;
    ModeSelection * modeselection;
    TriggerMode * triggermode;
    Inflation_Deflation_Timing * inflation_Deflation_Timing;
    InflationRatio * inflationRatio;
    BalloonVolume * balloonvolume;
    Set * set;
    Blank1 * blank1;
    Blank2 * blank2;
    AlarmSystem * alarmsystem;
    MessageManagement * messageManagement;
    Level1Alarm * level1alarm;
    ReadFile * readFile;
 signals:
        // 用于触发Worker开始工作
        void startWork(int maxCount);

private slots:
    void onWorkFinished(int result);
    void onProgressUpdated(int value);

private:
    QThread m_sendingthread;
   SendingThread * sendingthread;


private:
    Ui::Homepage *ui;
};


#endif //IABPUI_HOMEPAGE_H