//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MessageManagement.h" resolved

#include "../include/messagemanagement.h"
#include "ui_messagemanagement.h"
#include "level1alarm.h" // 引入告警头文件
#include <QMovie>

MessageManagement::MessageManagement(QWidget *parent) : QWidget(parent), ui(new Ui::MessageManagement) {
    ui->setupUi(this);
    move(68 , 68);
    setVisible(false);
    ui->scrollArea->setWidgetResizable(true);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QPixmap backgroundPixmap(":/MessageManagement/Group 10568.png");
    if (!backgroundPixmap.isNull()) {
        ui->Label->setPixmap(backgroundPixmap.scaled(ui->Label->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        ui->Label->setScaledContents(true);
    }
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->Label->setProperty("mode","MessageManagement_Label");
    ui->Widget->setProperty("mode","MessageManagement_Widget");
    ui->Close_Button->setProperty("mode","Close_Button");
    ui->verticalLayout_2->setAlignment(Qt::AlignTop);
    QScroller::grabGesture(
        ui->scrollArea->viewport(),
        QScroller::LeftMouseButtonGesture
    );

    addLevel1Alarm("一级告警：系统检测到异常");
}

MessageManagement::~MessageManagement() {
    delete ui;
}
void MessageManagement::addLevel1Alarm(const QString &alarmText) {
    // 父对象指定为 scrollArea 的内部 widget，由 Qt 对象树负责内存管理
    Level1Alarm *alarm = new Level1Alarm(ui->scrollAreaWidgetContents); // 如果 ui 文件中内部容器名叫 scrollAreaWidgetContents

    // 如果需要设置自定义文本，可以在 Level1Alarm 中暴露一个 setText 接口
    // if (!alarmText.isEmpty()) {
    //     alarm->setAlarmText(alarmText);
    // }

    // 将告警条目加入滚动区域的纵向布局中
    ui->verticalLayout_2->addWidget(alarm);
}