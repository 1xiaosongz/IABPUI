//
// Created by Administrator on 2026/7/3.
//

#ifndef IABPUI_HORIZONTALREFERENCELINE_H
#define IABPUI_HORIZONTALREFERENCELINE_H

#include <QWidget>
#include <QDial>

QT_BEGIN_NAMESPACE

namespace Ui {
    class HorizontalReferenceLine;
}

QT_END_NAMESPACE

class HorizontalReferenceLine : public QDial {
    Q_OBJECT

public:
    explicit HorizontalReferenceLine(QWidget *parent = nullptr);

    ~HorizontalReferenceLine() override;

    void setVisible(bool visible) override;
    bool visibleFlag() const;

    // 在类内部或外部调用以隐藏控件
    void hideSelf();
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int positionToValue(const QPoint &pos) const;

    Ui::HorizontalReferenceLine *ui;
    bool m_visible = true;
    // 外观参数
    int m_ringWidth = 12;       // 圆环宽度
    int m_handleRadius = 10;    // 滑块半径
    // 【新增】用于精确追踪圈数的变量
    mutable double m_lastAngle = -1.0; // 记录上一次的绝对角度 (0-360)
};


#endif //IABPUI_HORIZONTALREFERENCELINE_H
