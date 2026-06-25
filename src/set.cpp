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
    move( 345, 310);
    // setVisible(false);
    ui->Label->setProperty("mode","Label_SET");
    ui->Help_Button->setProperty("mode","Help_Button");

    ui->pushButton->setStyleSheet("QPushButton { background-image:url(:/Set/Group 10800.png); }");
    ui->pushButton_2->setStyleSheet("QPushButton { background-image:url(:/Set/Group 10799.png); }");
    ui->pushButton_3->setStyleSheet("QPushButton { background-image:url(:/Set/Group 10797.png); }");
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(0);});
    connect(ui->pushButton_2, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(1);});
    connect(ui->pushButton_3, &QPushButton::clicked, this, [=]() {
    ui->stackedWidget->setCurrentIndex(2);});
    ui->page->setObjectName("page");
    ui->page_2->setObjectName("page");
    ui->page_3->setObjectName("page");
    ui->Trumpet_Label->setProperty("mode1","Trumpet_Label");
    ui->label->setProperty("mode","30px,colour255,255,255");
    ui->label_2->setProperty("mode","30px,colour255,255,255");
    ui->label_3->setProperty("mode","30px,colour255,255,255");
    refreshStyle(ui->Trumpet_Label);
    refreshStyle(ui->label);
    refreshStyle(ui->label_2);
    refreshStyle(ui->label_3);
    ui->label_6->setProperty("mode","30px,colour255,255,255");
    ui->label_7->setProperty("mode","30px,colour255,255,255");
    ui->label_8->setProperty("mode","30px,colour255,255,255");
    ui->label_9->setProperty("mode","30px,colour255,255,255");
    ui->label_10->setProperty("mode","30px,colour255,255,255");

    refreshStyle(ui->label_6);
    refreshStyle(ui->label_7);
    refreshStyle(ui->label_8);
    refreshStyle(ui->label_9);
    refreshStyle(ui->label_10);

    // 1. 初始化 QSlider 范围（通常是 0 - 100）
    ui->horizontalSlider->setRange(0, 100);
    ui->horizontalSlider->setValue(70); // 默认初始值

    // 2. 初始化 Label 样式（白色字体、加粗、字号）
    ui->label_5->setProperty("mode","20px,colour255,255,255");
    refreshStyle(ui->label_5);
    ui->label_5->setText(QString("%1%").arg(ui->horizontalSlider->value()));

    // 3. 信号与槽联动：当滑动条数值改变时，同步更新 Label
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [=](int value){
        ui->label_5->setText(QString::number(value) + "%");
    });
    ui->horizontalSlider->setRange(0, 100);     // 设置范围 0 ~ 100
    ui->horizontalSlider->setSingleStep(1);     // 每次微调 1
    ui->horizontalSlider->setValue(70);         // 初始值设为 70

    /*----- 时间日期   ----*/
    ui->CalendarWidget->setNavigationBarVisible(false);
    ui->CalendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->CalendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    QTextCharFormat whiteFormat;
    whiteFormat.setForeground(Qt::white);
    // 2. 分别设置周六和周日的文本格式
    ui->CalendarWidget->setWeekdayTextFormat(Qt::Saturday, whiteFormat);
    ui->CalendarWidget->setWeekdayTextFormat(Qt::Sunday, whiteFormat);

    ui->CalendarWidget->setStyleSheet(R"(
QCalendarWidget QTableView QHeaderView::section:horizontal {
    background-color: black;
    color: white;
    font-weight: bold;
    border: none;
}
)");
    m_currentMonth = QDate::currentDate();
    ui->CalendarWidget->setCurrentPage(m_currentMonth.year(),m_currentMonth.month());
    // =================================================================
    // ★【只改这里】获取当天日期，并将它的字体颜色单独设置为蓝色，同时加粗
    // =================================================================
    QTextCharFormat todayTextFormat;
    todayTextFormat.setForeground(QBrush(QColor("#0094ff"))); // 设置为蓝色
    todayTextFormat.setFontWeight(QFont::Bold);              // 字体加粗突出
    ui->CalendarWidget->setDateTextFormat(m_currentMonth, todayTextFormat);
    // =================================================================
    // ★【新增】让日历真正选中并高亮“今天”这一天
    ui->CalendarWidget->setSelectedDate(m_currentMonth);
    ui->Month_Button->setText(m_currentMonth.toString("MMMM yyyy") + " >");
    connect(ui->Next_Button,&QPushButton::clicked,this,[this]()
{
    m_currentMonth = m_currentMonth.addMonths(1);
    ui->CalendarWidget->setCurrentPage(m_currentMonth.year(),m_currentMonth.month());
    ui->Month_Button->setText(m_currentMonth.toString("MMMM yyyy") + " >");
});
    connect(ui->Prev_Button,&QPushButton::clicked,this,[this]()
{
    m_currentMonth = m_currentMonth.addMonths(-1);
    ui->CalendarWidget->setCurrentPage(m_currentMonth.year(),m_currentMonth.month());
    ui->Month_Button->setText(m_currentMonth.toString("MMMM yyyy") + " >");
});
//=========时间================//
    ui->SetTime_Label->setProperty("mode","30px,colour255,255,255,font-weight: normal");
    refreshStyle(ui->SetTime_Label);
    for(int i=0;i<1;i++)
    {
        ui->Hour_List->addItem("");
        ui->Minute_List->addItem("");
        ui->Second_List->addItem("");
        ui->AmPm_List->addItem("");
    }
    for(int i=0;i<24;i++)
    {
        ui->Hour_List->addItem(QString("%1").arg(i,2,10,QChar('0')));
    }
    for(int i=0;i<60;i++)
    {
        QString text =QString("%1").arg(i,2,10,QChar('0'));
        ui->Minute_List->addItem(text);
        ui->Second_List->addItem(text);
    }
    ui->AmPm_List->addItem("AM");
    ui->AmPm_List->addItem("PM");
    for(int i=0;i<1;i++)
    {
        ui->Hour_List->addItem("");
        ui->Minute_List->addItem("");
        ui->Second_List->addItem("");
        ui->AmPm_List->addItem("");
    }
    CenterCurrentItem(ui->Hour_List);
    CenterCurrentItem(ui->Minute_List);
    CenterCurrentItem(ui->Second_List);
    CenterCurrentItem(ui->AmPm_List);
    connect(ui->Hour_List,&QListWidget::currentRowChanged,this,[this](){
        CenterCurrentItem(ui->Hour_List);});
    connect(ui->Minute_List,&QListWidget::currentRowChanged,this,[this](){
       CenterCurrentItem(ui->Minute_List);});
    connect(ui->Second_List,&QListWidget::currentRowChanged,this,[this](){
       CenterCurrentItem(ui->Second_List);});
    connect(ui->AmPm_List,&QListWidget::currentRowChanged,this,[this](){
       CenterCurrentItem(ui->AmPm_List);});
}

Set::~Set() {
    delete ui;
}
void Set::refreshStyle(QWidget* w)
{
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update();
}

void Set::CenterCurrentItem(QListWidget *list)
{

    if(!list)
        return;

    if(!list->currentItem())
        return;

    list->scrollToItem(
        list->currentItem(),
        QAbstractItemView::PositionAtCenter);
}
