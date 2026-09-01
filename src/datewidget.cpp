//
// Created by Administrator on 2026/7/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DateWidget.h" resolved

#include "datewidget.h"
#include "ui_DateWidget.h"
#include <QTextCharFormat>
#include <QLocale>
#include <QStyle>
DateWidget::DateWidget(QWidget *parent) : QWidget(parent), ui(new Ui::DateWidget) {
    ui->setupUi(this);
    ui->ClearDate_Button->setProperty("type", "ClearDate_Button");
    ui->Cancel_Button->setProperty("type", "Cancel_Button");
    // 默认初始状态为日期视图
    m_currentMode = DayView;
    ui->YearToDateStackedWidget->setCurrentIndex(0); // 确保一开始显示日历
    // 1. 初始化日历样式与属性
    ui->CalendarWidget->setNavigationBarVisible(false);
    ui->CalendarWidget->setLocale(QLocale(QLocale("zh_CN")));
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
    // 计算当前年份所属的12年周期的起始年 (例如2026年， 2026 - (2026%12) 得到基准，或者像Windows一样以0结尾：2020)
    // 这里我们直接按Windows习惯，取整十的年份作为起始，一页展示12年
    m_startYearOfDecade = (m_currentMonth.year() / 10) * 10;
    // 初始化月份按钮组
    initMonthView();
    initYearView();
    // 更新头部文字
    updateHeader();
    // 标题按钮点击：点击 "2026年7月 >" 切换到月份视图
    connect(ui->Month_Button, &QPushButton::clicked, this, &DateWidget::onTitleButtonClicked);
    // 3. 信号槽连接
    connect(ui->Prev_Button, &QPushButton::clicked, this, [this]() {
       if (m_currentMode == DayView) {
           m_currentMonth = m_currentMonth.addMonths(-1);
           ui->CalendarWidget->setCurrentPage(m_currentMonth.year(), m_currentMonth.month());
       } else if (m_currentMode == MonthView) {
           m_currentMonth = m_currentMonth.addYears(-1);
       } else if (m_currentMode == YearView) {
           m_startYearOfDecade -= 12; // 年份视图下，向前翻整个年代（12年）
           updateYearButtons();
       }
       updateHeader();
   });
    connect(ui->Next_Button, &QPushButton::clicked, this, [this]() {
        if (m_currentMode == DayView) {
            m_currentMonth = m_currentMonth.addMonths(1);
            ui->CalendarWidget->setCurrentPage(m_currentMonth.year(), m_currentMonth.month());
        } else if (m_currentMode == MonthView) {
            m_currentMonth = m_currentMonth.addYears(1);
        } else if (m_currentMode == YearView) {
            m_startYearOfDecade += 12; // 年份视图下，向后翻整个年代（12年）
            updateYearButtons();
        }
        updateHeader();
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

// 初始化手动拖拽的12个按钮
void DateWidget::initMonthView() {
    m_monthButtonGroup = new QButtonGroup(this);
    // 假设这是你的 12 个按钮
    QList<QPushButton*> monthButtons = {
        ui->MonthBtn_1, ui->MonthBtn_2, ui->MonthBtn_3, ui->MonthBtn_4,
        ui->MonthBtn_5, ui->MonthBtn_6, ui->MonthBtn_7, ui->MonthBtn_8,
        ui->MonthBtn_9, ui->MonthBtn_10, ui->MonthBtn_11, ui->MonthBtn_12
    };

    for (int i = 0; i < monthButtons.size(); ++i) {
        // 1. 给按钮设置自定义属性，方便 QSS 精准匹配
        monthButtons[i]->setProperty("type", "CalendarGridBtn");
        // 2. 关键：强制刷新 QSS 样式引擎
        monthButtons[i]->style()->unpolish(monthButtons[i]);
        monthButtons[i]->style()->polish(monthButtons[i]);
        // 将按钮加进组里（ID 为 1 到 12）
        m_monthButtonGroup->addButton(monthButtons[i], i + 1);
    }

    // 当点击组内的任意月份按钮时，触发此槽函数
    connect(m_monthButtonGroup, &QButtonGroup::idClicked, this, [this](int id) {
        // id 就是对应的月份 (1-12)
        m_currentMonth = QDate(m_currentMonth.year(), id, 1);
        ui->CalendarWidget->setCurrentPage(m_currentMonth.year(), m_currentMonth.month());

        // 切回日期视图
        m_currentMode = DayView;
        ui->YearToDateStackedWidget->setCurrentIndex(0);
        updateHeader();
    });
}
// 新增：初始化手动拖拽的12个年份按钮
void DateWidget::initYearView() {
    m_yearButtonGroup = new QButtonGroup(this);
    // 请将这里的 YearBtn_1 等替换为你 UI 里面实际的年份按钮 ObjectName
    // 按钮ID我们直接从 0 到 11 排序
    QList<QPushButton*> yearButtons = {
        ui->YearBtn_1, ui->YearBtn_2, ui->YearBtn_3, ui->YearBtn_4,
        ui->YearBtn_5, ui->YearBtn_6, ui->YearBtn_7, ui->YearBtn_8,
        ui->YearBtn_9, ui->YearBtn_10, ui->YearBtn_11, ui->YearBtn_12
    };

    for (int i = 0; i < yearButtons.size(); ++i) {
        // 关键：让年份按钮和月份按钮共享同一个 QSS 属性名
        yearButtons[i]->setProperty("type", "CalendarGridBtn");
        m_yearButtonGroup->addButton(yearButtons[i], i);
    }

    // 动态刷新一次按钮上显示的文本内容
    updateYearButtons();

    // 点击某个具体年份时的逻辑
    connect(m_yearButtonGroup, &QButtonGroup::idClicked, this, [this](int id) {
        // 计算出点击的实际年份
        int targetYear = m_startYearOfDecade + id;
        m_currentMonth = QDate(targetYear, m_currentMonth.month(), 1);

        // 切回月份视图
        m_currentMode = MonthView;
        ui->YearToDateStackedWidget->setCurrentIndex(1); // 对应月份网格的 Page
        updateHeader();
    });
}
// 统一控制头部文本显示逻辑
void DateWidget::updateHeader() {
    if (m_currentMode == DayView) {
        ui->Month_Button->setText(QString(" %1 年 %2 月 >").arg(m_currentMonth.year()).arg(m_currentMonth.month()));
    } else if (m_currentMode == MonthView) {
        ui->Month_Button->setText(QString(" %1 年 >").arg(m_currentMonth.year()));
    } else if (m_currentMode == YearView) {
        // 年份视图下显示年代区间，例如： "2020-2031 >"
        ui->Month_Button->setText(QString(" %1 - %2 >").arg(m_startYearOfDecade).arg(m_startYearOfDecade + 11));
    }
}
// 新增：根据当前的 m_startYearOfDecade 动态刷新12个按钮的文字
void DateWidget::updateYearButtons() {
    QList<QAbstractButton*> buttons = m_yearButtonGroup->buttons();
    for (int i = 0; i < buttons.size(); ++i) {
        int year = m_startYearOfDecade + i;
        buttons[i]->setText(QString::number(year));
    }
}
// 标题按钮点击槽函数
void DateWidget::onTitleButtonClicked() {
    if (m_currentMode == DayView) {
        m_currentMode = MonthView;
        ui->YearToDateStackedWidget->setCurrentIndex(1); // 进入月份页
        updateHeader();
    } else if (m_currentMode == MonthView) {
        m_currentMode = YearView;
        // 在进入年份视图前，确保当前的年份包含在当前这一页的区间内
        m_startYearOfDecade = (m_currentMonth.year() / 10) * 10;
        updateYearButtons();

        ui->YearToDateStackedWidget->setCurrentIndex(2); // 进入年份页 (Page 2)
        updateHeader();
    }
}
