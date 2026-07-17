//
// Created by Administrator on 2026/7/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DateWidget.h" resolved

#include "datewidget.h"
#include "ui_DateWidget.h"
#include <QTextCharFormat>

DateWidget::DateWidget(QWidget *parent) : QWidget(parent), ui(new Ui::DateWidget) {
    ui->setupUi(this);
    // 1. 初始化日历样式与属性
    ui->CalendarWidget->setNavigationBarVisible(false);
    ui->CalendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
    ui->CalendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    QTextCharFormat whiteFormat;
    whiteFormat.setForeground(Qt::white);
    ui->CalendarWidget->setWeekdayTextFormat(Qt::Saturday, whiteFormat);
    ui->CalendarWidget->setWeekdayTextFormat(Qt::Sunday, whiteFormat);

    // 2. 设置今天高亮
    m_currentMonth = QDate::currentDate();
    ui->CalendarWidget->setCurrentPage(m_currentMonth.year(), m_currentMonth.month());

    QTextCharFormat todayTextFormat;
    todayTextFormat.setForeground(QBrush(QColor("#0094ff")));
    todayTextFormat.setFontWeight(QFont::Bold);
    ui->CalendarWidget->setDateTextFormat(m_currentMonth, todayTextFormat);
    ui->CalendarWidget->setSelectedDate(m_currentMonth);

    ui->Month_Button->setText(m_currentMonth.toString("MMMM yyyy") + " >");

    // 3. 信号槽连接
    connect(ui->Next_Button, &QPushButton::clicked, this, [this]() {
        m_currentMonth = m_currentMonth.addMonths(1);
        ui->CalendarWidget->setCurrentPage(m_currentMonth.year(), m_currentMonth.month());
        ui->Month_Button->setText(m_currentMonth.toString("MMMM yyyy") + " >");
    });

    connect(ui->Prev_Button, &QPushButton::clicked, this, [this]() {
        m_currentMonth = m_currentMonth.addMonths(-1);
        ui->CalendarWidget->setCurrentPage(m_currentMonth.year(), m_currentMonth.month());
        ui->Month_Button->setText(m_currentMonth.toString("MMMM yyyy") + " >");
    });

    // 当用户点击日历中的某一天时，触发自定义信号
    connect(ui->CalendarWidget, &QCalendarWidget::clicked, this, [this](const QDate &date){
        emit dateChanged(date);
    });
}

DateWidget::~DateWidget() {
    delete ui;
}
QDate DateWidget::selectedDate() const
{
    return ui->CalendarWidget->selectedDate();
}