//
// Created by Administrator on 2026/7/16.
//

#ifndef IABPUI_DATEWIDGET_H
#define IABPUI_DATEWIDGET_H

#include <QWidget>
#include <QDate>
#include <QButtonGroup>
// 在类定义外部增加视图状态枚举
enum CalendarViewMode {
    DayView, // 日期视图
    MonthView, // 月份视图
    YearView // 年份视图
};
QT_BEGIN_NAMESPACE

namespace Ui {
    class DateWidget;
}

QT_END_NAMESPACE

class DateWidget : public QWidget {
    Q_OBJECT

public:
    explicit DateWidget(QWidget *parent = nullptr);

    ~DateWidget() override;
    // 暴露一个公共接口，用于让外部获取当前选中的日期
    QDate selectedDate() const;

    signals:
    // 当用户在日历里点击/选择了新日期时，发送此信号通知外部
    void dateChanged(const QDate &date);
private:
    Ui::DateWidget *ui;
    QDate m_currentMonth;
    CalendarViewMode m_currentMode ;
    QButtonGroup *m_monthButtonGroup; // 用于集中管理12个月份按钮
    QButtonGroup *m_yearButtonGroup;
    int m_startYearOfDecade;
    // 更新头部文本的函数
    void updateHeader();
    void initMonthView(); // 初始化月份按钮的绑定

    // 3. 增加初始化年份网格和刷新年份文字的函数
    void initYearView();
    void updateYearButtons();
private slots:
    void onTitleButtonClicked(); // 处理左上角那个 "2026年7月 >" 按钮的点击
};


#endif //IABPUI_DATEWIDGET_H
