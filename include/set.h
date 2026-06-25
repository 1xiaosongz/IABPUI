//
// Created by Administrator on 2026/4/8.
//

#ifndef IABPUI_SET_H
#define IABPUI_SET_H

#include <QWidget>
#include <QTabBar>
#include <QEvent>
#include <QMouseEvent>
#include <QSlider>
#include <QDate>
#include <QCalendarWidget>
#include <QPainter>
#include <QListWidget>
QT_BEGIN_NAMESPACE

namespace Ui {
    class Set;
}

QT_END_NAMESPACE

class Set : public QWidget {
    Q_OBJECT

public:
    explicit Set(QWidget *parent = nullptr);

    ~Set() override;
    void refreshStyle(QWidget* w);

private:
    QDate m_currentMonth;
    void CenterCurrentItem(QListWidget *list);
private slots:
    // void UpdateTime();
private:
    Ui::Set *ui;
};




class TouchSlider : public QSlider {
protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            // 计算点击位置占整个轨道的比例
            double val = static_cast<double>(event->x()) / width();
            int targetValue = minimum() + val * (maximum() - minimum());
            setValue(targetValue);
            event->accept();
        }
        QSlider::mousePressEvent(event); // 保证原有的滑动逻辑不受影响
    }
};


#endif //IABPUI_SET_H