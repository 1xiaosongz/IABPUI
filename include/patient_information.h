//
// Created by Administrator on 2026/9/3.
//

#ifndef IABPUI_PATIENT_INFORMATION_H
#define IABPUI_PATIENT_INFORMATION_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class patient_information;
}

QT_END_NAMESPACE

class patient_information : public QWidget {
    Q_OBJECT

public:
    explicit patient_information(QWidget *parent = nullptr);

    ~patient_information() override;

private:
    Ui::patient_information *ui;
};


#endif //IABPUI_PATIENT_INFORMATION_H
