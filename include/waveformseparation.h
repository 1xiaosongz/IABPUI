//
// Created by Administrator on 2026/3/31.
//

#ifndef IABPUI_WAVEFORMSEPARATION_H
#define IABPUI_WAVEFORMSEPARATION_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class WaveformSeparation;
}

QT_END_NAMESPACE

class WaveformSeparation : public QWidget {
    Q_OBJECT

public:
    explicit WaveformSeparation(QWidget *parent = nullptr);

    ~WaveformSeparation() override;

private:
    Ui::WaveformSeparation *ui;
};


#endif //IABPUI_WAVEFORMSEPARATION_H