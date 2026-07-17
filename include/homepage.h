//
// Created by Administrator on 2026/5/28.
//

#ifndef IABPUI_HOMEPAGE_H
#define IABPUI_HOMEPAGE_H

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
#include "alarmsystem.h"
#include "messagemanagement.h"
#include "level1alarm.h"
#include "pressurezeroadjustment.h"
#include "horizontalreferenceline.h"
#include "logexport.h"
#include <QObject>
#include "helpinterface.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class HomePage;
}

QT_END_NAMESPACE

class HomePage : public QWidget {
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);

    ~HomePage() override;
private:
    TopBar * topbar;
    WaveformSeparation * waveformseparation;
    BottomNavigationBar * bottomnavigationbar;
    StatusBar * statusbar;
    ModeSelection * modeselection;
    TriggerMode * triggermode;
    Inflation_Deflation_Timing * inflation_Deflation_Timing;
    InflationRatio * inflationRatio;
    BalloonVolume * balloonvolume;
    Set * set;
    PressureZeroAdjustment * pressurezeroadjustment;
    AlarmSystem * alarmsystem;
    MessageManagement * messageManagement;
    Level1Alarm * level1alarm;
    HorizontalReferenceLine * horizontalReferenceLine;
    // HelpInterface * helpinterface;

    LogExport * logexport;

private:
    Ui::HomePage *ui;
};


#endif //IABPUI_HOMEPAGE_H
