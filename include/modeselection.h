//
// Created by Administrator on 2026/4/1.
//

#ifndef IABPUI_MODESELECTION_H
#define IABPUI_MODESELECTION_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class ModeSelection;
}

QT_END_NAMESPACE

class ModeSelection : public QWidget {
    Q_OBJECT

public:
    explicit ModeSelection(QWidget *parent = nullptr);

    ~ModeSelection() override;

private:
    Ui::ModeSelection *ui;
};


#endif //IABPUI_MODESELECTION_H