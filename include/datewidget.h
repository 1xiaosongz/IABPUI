//
// Created by Administrator on 2026/7/16.
//

#ifndef IABPUI_DATEWIDGET_H
#define IABPUI_DATEWIDGET_H

#include <QWidget>
#include <QDate>

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
};


#endif //IABPUI_DATEWIDGET_H
