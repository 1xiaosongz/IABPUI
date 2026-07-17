//
// Created by Administrator on 2026/7/3.
//

// You may need to build the project (run Qt uic code generator) to get "ui_HorizontalReferenceLine.h" resolved

#include "horizontalreferenceline.h"
#include "ui_HorizontalReferenceLine.h"
#include <QPainter>
#include <QConicalGradient>
#include <QtMath>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPen>

HorizontalReferenceLine::HorizontalReferenceLine(QWidget *parent) : QDial(parent),
                                                                    ui(new Ui::HorizontalReferenceLine),
                                                                    m_visible(true) {
    ui->setupUi(this);
    // 【新增这行】设置背景透明属性
    setAttribute(Qt::WA_TranslucentBackground, true);
    setMinimum(0);
    setMaximum(300);
    setWrapping(true);
    setNotchesVisible(false);
    setMouseTracking(true);
    setAttribute(Qt::WA_OpaquePaintEvent, false);
    this->setFixedSize(110, 110); // 固定宽高为 50x50
    // 如果它不在布局中，而是绝对定位，你可以同时设置坐标：
    move(1384, 80);     // 只控制它出现的位置
    setVisible(false);
}

HorizontalReferenceLine::~HorizontalReferenceLine() {
    delete ui;
}

void HorizontalReferenceLine::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_lastAngle = -1.0; // 按下时清空历史角度，重新追踪
        setValue(positionToValue(event->pos()));
        event->accept();
    } else {
        QDial::mousePressEvent(event);
    }
}
void HorizontalReferenceLine::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        setValue(positionToValue(event->pos()));
        event->accept();
    } else {
        QDial::mouseMoveEvent(event);
    }
}

void HorizontalReferenceLine::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_lastAngle = -1.0; // 释放时清空
        event->accept();
    } else {
        QDial::mouseReleaseEvent(event);
    }
}
void HorizontalReferenceLine::setVisible(bool visible) {
    m_visible = visible;
    QWidget::setVisible(visible);
}

bool HorizontalReferenceLine::visibleFlag() const {
    return m_visible;
}

void HorizontalReferenceLine::hideSelf() {
    setVisible(false);
}

int HorizontalReferenceLine::positionToValue(const QPoint &pos) const {
    const QPointF center(width() / 2.0, height() / 2.0);
    QPointF delta = pos - center;
    if (qFuzzyIsNull(delta.manhattanLength())) {
        return value();
    }
    // 1. 计算当前鼠标相对于中心的绝对角度 (0 ~ 360 度，以 12 点钟为 0 度顺时针展开)
    double angle = qAtan2(delta.y(), delta.x());
    double degrees = qRadiansToDegrees(angle) + 90.0;
    if (degrees < 0.0) degrees += 360.0;
    if (degrees >= 360.0) degrees -= 360.0;
    int currentValue = value();

    // 如果是第一次点击，或者刚释放完，先同步角度，不改变数值
    if (m_lastAngle < 0) {
        m_lastAngle = degrees;
        return currentValue;
    }
    // 2. 计算角度差值
    double diff = degrees - m_lastAngle;
    // 跨越 12 点钟方向的边界修正
    if (diff < -180.0)  diff += 360.0; // 顺时针跨 12 点 (例如从 350度 变到 10度)
    if (diff > 180.0)   diff -= 360.0; // 逆时针跨 12 点 (例如从 10度 变到 350度)
    m_lastAngle = degrees;
    // 3. 将角度变化量转换为数值变化量 (一圈 360 度对应 100 个值)
    double valueDelta = (diff / 360.0) * 100.0;

    // 四舍五入得到整数增量，如果太小则不改变
    int newValue = currentValue + qRound(valueDelta);

    // 4. 严格限制边界 (0 - 300 锁死)
    if (newValue <= 0) {
        return 0; // 逆时针退到0，锁死
    }
    if (newValue >= 300) {
        return 300; // 顺时针满3圈，锁死
    }
    return newValue;
}
void HorizontalReferenceLine::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPointF center(width()/2.0, height()/2.0);
    const int radius = qMin(width(),height())/2 - m_handleRadius - 4;
    QRectF circle(center.x()-radius, center.y()-radius, radius*2, radius*2);

    // 底部圆环暗色轨道
    QPen basePen(QColor(235, 235, 235, 40), m_ringWidth);
    basePen.setCapStyle(Qt::RoundCap);
    painter.setPen(basePen);
    painter.drawEllipse(circle);

    // 获取当前真实进度
    int curValue = value();

    // 准备三种颜色
    QColor color1(46, 204, 113); // 绿色
    QColor color2(231, 76, 60);  // 红色
    QColor color3(52, 152, 219); // 蓝色

    QPen progressPen;
    progressPen.setWidth(m_ringWidth);
    progressPen.setCapStyle(Qt::RoundCap);

    //---------------------------------------------------------
    // 动态分层绘制进度条
    //---------------------------------------------------------
    if (curValue <= 100) {
        // 第一圈：只画绿色
        double p1 = curValue / 100.0;
        progressPen.setColor(color1);
        painter.setPen(progressPen);
        painter.drawArc(circle, 90 * 16, -p1 * 360 * 16);
    }
    else if (curValue <= 200) {
        // 第二圈：背景是满绿，上面覆盖红色的当前进度
        progressPen.setColor(color1);
        painter.setPen(progressPen);
        painter.drawArc(circle, 90 * 16, -360 * 16); // 满绿

        double p2 = (curValue - 100) / 100.0;
        progressPen.setColor(color2);
        painter.setPen(progressPen);
        painter.drawArc(circle, 90 * 16, -p2 * 360 * 16); // 红
    }
    else {
        // 第三圈：背景是满红，上面覆盖蓝色的当前进度
        progressPen.setColor(color2);
        painter.setPen(progressPen);
        painter.drawArc(circle, 90 * 16, -360 * 16); // 满红

        double p3 = (curValue - 200) / 100.0;
        progressPen.setColor(color3);
        painter.setPen(progressPen);
        painter.drawArc(circle, 90 * 16, -p3 * 360 * 16); // 蓝
    }

    // 中心圆盘无色挖空
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(center, radius - m_ringWidth, radius - m_ringWidth);

    //---------------------------------------------------------
    // 计算滑块位置（滑块应该基于当前圈的绝对角度显示位置）
    //---------------------------------------------------------
    int displayValue = curValue % 100;
    if (curValue == 300) displayValue = 100; // 满300停在12点位置

    double lapPercent = displayValue / 100.0;
    double currentAngle = -90.0 + lapPercent * 360.0;
    double rad = qDegreesToRadians(currentAngle);
    QPointF handleCenter(center.x() + radius * qCos(rad), center.y() + radius * qSin(rad));

    // 绘制白色滑块本体
    painter.setBrush(Qt::white);
    painter.drawEllipse(handleCenter, m_handleRadius, m_handleRadius);
}
