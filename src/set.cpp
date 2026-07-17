//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Set.h" resolved

#include "../include/set.h"

#include <qstyle.h>
#include <QTabBar>
#include "ui_Set.h"
#include <QFile>
#include <QListWidget>
#include <qtextformat.h>
#include <QScrollBar>
#include <QHeaderView>
#include <QTableView>
#include <QStyleFactory>

Set::Set(QWidget *parent) : QWidget(parent), ui(new Ui::Set) {
    ui->setupUi(this);
    move(345, 310);
    setVisible(false);
    ui->Label->setProperty("mode", "Label_SET");
    ui->Help_Button->setProperty("mode", "Help_Button");
    ui->Set_Confirm_Button->setProperty("mode", "Set_Confirm_Button");
    ui->Sound_Off->setProperty("mode", "Sound_Off_True");
    ui->Sound_Low->setProperty("mode", "Sound_Low_True");
    ui->Sound_Medium->setProperty("mode", "Sound_Medium_True");
    ui->Sound_High->setProperty("mode", "Sound_High_True");
    ui->Standby_Off->setProperty("mode", "Standby_Off_True");
    ui->Standby_On->setProperty("mode", "Standby_On_True");
    ui->ECG_Off->setProperty("mode", "ECG_Off_True");
    ui->ECG_On->setProperty("mode", "ECG_On_True");
    ui->Inflation_Interval_Off->setProperty("mode", "Inflation_Interval_Off_True");
    ui->Inflation_Interval_On->setProperty("mode", "Inflation_Interval_On_True");
    ui->Brightness_Off->setProperty("mode", "Brightness_Off_True");
    ui->Brightness_High->setProperty("mode", "Brightness_High_True");
    ui->Brightness_Low->setProperty("mode", "Brightness_Low_True");
    ui->Brightness_Medium->setProperty("mode", "Brightness_Medium_True");
    ui->ScanningSpeed_25->setProperty("mode", "ScanningSpeed_25_True");
    ui->ScanningSpeed_50->setProperty("mode", "ScanningSpeed_50_True");
    ui->Timing_7S->setProperty("mode", "Timing_7S_True");
    ui->Timing_15S->setProperty("mode", "Timing_15S_True");
    ui->Timing_30S->setProperty("mode", "Timing_30S_True");
    ui->Timing_60S->setProperty("mode", "Timing_60S_True");
    ui->Call_The_Police_Off->setProperty("mode", "Call_The_Police_Off_True");
    ui->Call_The_Police_15Min->setProperty("mode", "Call_The_Police_15Min_True");
    ui->Call_The_Police_30Min->setProperty("mode", "Call_The_Police_30Min_True");
    ui->Call_The_Police_1Hour->setProperty("mode", "Call_The_Police_1Hour_True");
    ui->Call_The_Police_2Hour->setProperty("mode", "Call_The_Police_2Hour_True");
    ui->Call_The_Police_4Hour->setProperty("mode", "Call_The_Police_4Hour_True");
    ui->Log_Printing->setProperty("mode", "Log_Printing_True");
    refreshStyle(ui->ECG_Off);
    refreshStyle(ui->ECG_On);
    refreshStyle(ui->Inflation_Interval_Off);
    refreshStyle(ui->Inflation_Interval_On);
    refreshStyle(ui->Brightness_Off);
    refreshStyle(ui->Brightness_High);
    refreshStyle(ui->Brightness_Low);
    refreshStyle(ui->Brightness_Medium);
    refreshStyle(ui->ScanningSpeed_25);
    refreshStyle(ui->ScanningSpeed_50);
    refreshStyle(ui->Timing_7S);
    refreshStyle(ui->Timing_15S);
    refreshStyle(ui->Timing_30S);
    refreshStyle(ui->Timing_60S);
    refreshStyle(ui->Call_The_Police_Off);
    refreshStyle(ui->Call_The_Police_15Min);
    refreshStyle(ui->Call_The_Police_30Min);
    refreshStyle(ui->Call_The_Police_1Hour);
    refreshStyle(ui->Call_The_Police_2Hour);
    refreshStyle(ui->Call_The_Police_4Hour);
    refreshStyle(ui->Log_Printing);

    ui->label_26->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_18->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->Blood_Pressure_Increase_Botton->setProperty("mode", "up_arrow_True");
    ui->Blood_Pressure_Drops_Botton->setProperty("mode", "down_arrow_True");
    ui->Increased_Counterpulsation_Pressure_Botton->setProperty("mode", "up_arrow_True");
    ui->Counterpulsation_Pressure_Reduction_Botton->setProperty("mode", "down_arrow_True");
    ui->Label_14->setProperty("mode", "Digit_Frame");
    ui->Label_13->setProperty("mode", "Digit_Frame");
    ui->Anti_embolism_Pressure_Reading_Label->setText("666");
    ui->Blood_Pressure_Reading_Label->setText("999");
    ui->Anti_embolism_Pressure_Reading_Label->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->Blood_Pressure_Reading_Label->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    refreshStyle(ui->Blood_Pressure_Increase_Botton);
    refreshStyle(ui->Blood_Pressure_Drops_Botton);
    refreshStyle(ui->Increased_Counterpulsation_Pressure_Botton);
    refreshStyle(ui->Counterpulsation_Pressure_Reduction_Botton);
    refreshStyle(ui->Anti_embolism_Pressure_Reading_Label);
    refreshStyle(ui->Blood_Pressure_Reading_Label);
    refreshStyle(ui->label_26);
    refreshStyle(ui->label_18);
    refreshStyle(ui->Label_13);
    refreshStyle(ui->Label_14);
//----------按键连接子界面-------------
    // 第一步：把你的 13 个按钮按照顺序放进一个 QVector 容器中
    QVector<QPushButton *> setButtons = {
        ui->Set_Button_1, ui->Set_Button_2, ui->Set_Button_3, ui->Set_Button_4,
        ui->Set_Button_5, ui->Set_Button_6, ui->Set_Button_7, ui->Set_Button_8,
        ui->Set_Button_9, ui->Set_Button_10, ui->Set_Button_11, ui->Set_Button_12,
        ui->Set_Button_13, ui->Set_Button_14
    };

    // 第二步：用一个 for 循环，一次性搞定 13 个按钮的绑定
    for (int i = 0; i < setButtons.size(); ++i) {
        // 检查指针是否为空，防止在 UI 界面少画了按钮导致程序崩溃
        if (setButtons[i] != nullptr) {
            // 关键点：将当前的循环次数 i 传给 Lambda 表达式 [i]
            connect(setButtons[i], &QPushButton::clicked, this, [=]() {
                // 点击第 i 个按钮，右侧的 stackedWidget 就切到第 i 页
                ui->stackedWidget->setCurrentIndex(i);
            });
        }
    }
    ui->Trumpet_Label->setProperty("mode1", "Trumpet_Label");
    ui->label->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_2->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_3->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    refreshStyle(ui->Trumpet_Label);
    refreshStyle(ui->label);
    refreshStyle(ui->label_2);
    refreshStyle(ui->label_3);
    ui->label_6->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_7->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_8->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_9->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_10->setProperty("mode", "30px,colour255,255,255,AlignCenter");

    refreshStyle(ui->label_6);
    refreshStyle(ui->label_7);
    refreshStyle(ui->label_8);
    refreshStyle(ui->label_9);
    refreshStyle(ui->label_10);
    ui->label_14->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_15->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_16->setProperty("mode", "30px,colour255,255,255,AlignCenter");
    ui->label_17->setProperty("mode", "30px,colour255,255,255,AlignCenter");

    refreshStyle(ui->label_14);
    refreshStyle(ui->label_15);
    refreshStyle(ui->label_16);
    refreshStyle(ui->label_17);



    // 1. 初始化 QSlider 范围（通常是 0 - 100）
    ui->horizontalSlider->setRange(0, 100);
    ui->horizontalSlider->setValue(70); // 默认初始值

    // 2. 初始化 Label 样式（白色字体、加粗、字号）
    ui->label_5->setProperty("mode", "20px,colour255,255,255");
    refreshStyle(ui->label_5);
    ui->label_5->setText(QString("%1%").arg(ui->horizontalSlider->value()));

    // 3. 信号与槽联动：当滑动条数值改变时，同步更新 Label
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [=](int value) {
        ui->label_5->setText(QString::number(value) + "%");
    });
    ui->horizontalSlider->setRange(0, 100); // 设置范围 0 ~ 100
    ui->horizontalSlider->setSingleStep(1); // 每次微调 1
    ui->horizontalSlider->setValue(70); // 初始值设为 70


    //=========时间================//
    ui->SetTime_Label->setProperty("mode", "20px,colour255,255,255,font-weight: normal");
    refreshStyle(ui->SetTime_Label);
    for (int i = 0; i < 1; i++) {
        QListWidgetItem *item;
        item = new QListWidgetItem("");
        item->setTextAlignment(Qt::AlignCenter);
        ui->Hour_List->addItem(item);
        item = new QListWidgetItem("");
        item->setTextAlignment(Qt::AlignCenter);
        ui->Minute_List->addItem(item);
        item = new QListWidgetItem("");
        item->setTextAlignment(Qt::AlignCenter);
        ui->Second_List->addItem(item);
        item = new QListWidgetItem("");
        item->setTextAlignment(Qt::AlignCenter);
        ui->AmPm_List->addItem(item);
    }
    for (int i = 0; i < 24; i++) {
        // ui->Hour_List->addItem(QString("%1").arg(i,2,10,QChar('0')));
        QListWidgetItem *item = new QListWidgetItem(
            QString("%1").arg(i, 2, 10, QChar('0')));
        item->setTextAlignment(Qt::AlignCenter);
        ui->Hour_List->addItem(item);
    }
    for (int i = 0; i < 60; i++) {
        QString text = QString("%1").arg(i, 2, 10, QChar('0'));
        QListWidgetItem *minuteItem = new QListWidgetItem(text);
        minuteItem->setTextAlignment(Qt::AlignCenter);
        ui->Minute_List->addItem(minuteItem);
        QListWidgetItem *secondItem = new QListWidgetItem(text);
        secondItem->setTextAlignment(Qt::AlignCenter);
        ui->Second_List->addItem(secondItem);
    }
    QListWidgetItem *pm = new QListWidgetItem("PM");
    pm->setTextAlignment(Qt::AlignCenter);
    ui->AmPm_List->addItem(pm);
    QListWidgetItem *am = new QListWidgetItem("AM");
    am->setTextAlignment(Qt::AlignCenter);
    ui->AmPm_List->addItem(am);
    for (int i = 0; i < 1; i++) {
        ui->Hour_List->addItem("");
        ui->Minute_List->addItem("");
        ui->Second_List->addItem("");
        ui->AmPm_List->addItem("");
    }
    CenterCurrentItem(ui->Hour_List);
    CenterCurrentItem(ui->Minute_List);
    CenterCurrentItem(ui->Second_List);
    CenterCurrentItem(ui->AmPm_List);
    connect(ui->Hour_List, &QListWidget::currentRowChanged, this, [this]() {
        CenterCurrentItem(ui->Hour_List);
    });
    connect(ui->Minute_List, &QListWidget::currentRowChanged, this, [this]() {
        CenterCurrentItem(ui->Minute_List);
    });
    connect(ui->Second_List, &QListWidget::currentRowChanged, this, [this]() {
        CenterCurrentItem(ui->Second_List);
    });
    connect(ui->AmPm_List, &QListWidget::currentRowChanged, this, [this]() {
        CenterCurrentItem(ui->AmPm_List);
    });
    // =================================================================
    // ★【核心修改】获取系统当前时间并自动滚动到对应位置
    // =================================================================

    // 1. 获取系统当前的本地时间
    QTime currentTime = QTime::currentTime();
    int currentHour = currentTime.hour();
    int currentMinute = currentTime.minute();
    int currentSecond = currentTime.second();

    // 2. 计算时、分、秒在 QListWidget 中的目标行数
    // 因为你在开头 add 了一个空字符串项，所以实际 Row = 时间值 + 1
    int hourRow = currentHour + 1;
    int minuteRow = currentMinute + 1;
    int secondRow = currentSecond + 1;

    // 3. 设置 QListWidget 选中对应的行（会自动触发你写的 CenterCurrentItem 槽函数）
    ui->Hour_List->setCurrentRow(hourRow);
    ui->Minute_List->setCurrentRow(minuteRow);
    ui->Second_List->setCurrentRow(secondRow);

    // 4. 处理 AM / PM 判断与定位
    // 你的 AM/PM 列表顺序是：[0]: 空白, [1]: "PM", [2]: "AM", [3]: 空白
    int amPmRow = 1; // 默认给 PM
    if (currentHour < 12) {
        amPmRow = 2; // 如果小于 12 点，则选中 AM
    }
    ui->AmPm_List->setCurrentRow(amPmRow);
}

Set::~Set() {
    delete ui;
}

void Set::refreshStyle(QWidget *w) {
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update();
}

void Set::CenterCurrentItem(QListWidget *list) {
    if (!list)
        return;

    if (!list->currentItem())
        return;

    list->scrollToItem(
        list->currentItem(),
        QAbstractItemView::PositionAtCenter);
}
