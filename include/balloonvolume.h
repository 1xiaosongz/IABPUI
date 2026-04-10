//
// Created by Administrator on 2026/4/1.
//

#ifndef IABPUI_BALLOONVOLUME_H
#define IABPUI_BALLOONVOLUME_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class BalloonVolume;
}

QT_END_NAMESPACE

class BalloonVolume : public QWidget {
    Q_OBJECT

public:
    explicit BalloonVolume(QWidget *parent = nullptr);

    ~BalloonVolume() override;

private:
    Ui::BalloonVolume *ui;
};


#endif //IABPUI_BALLOONVOLUME_H