//
// Created by Administrator on 2026/6/9.
//

#ifndef IABPUI_HELPINTERFACE_H
#define IABPUI_HELPINTERFACE_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class HelpInterface;
}

QT_END_NAMESPACE

class HelpInterface : public QWidget {
    Q_OBJECT

public:
    explicit HelpInterface(QWidget *parent = nullptr);

    ~HelpInterface() override;

private:
    Ui::HelpInterface *ui;
};


#endif //IABPUI_HELPINTERFACE_H
