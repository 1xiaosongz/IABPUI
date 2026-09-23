//
// Created by Administrator on 2026/9/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CounterpulsationPressure.h" resolved

#include "counterpulsationpressure.h"
#include "ui_CounterpulsationPressure.h"


CounterpulsationPressure::CounterpulsationPressure(QWidget *parent) : QWidget(parent),
                                                                      ui(new Ui::CounterpulsationPressure) {
    ui->setupUi(this);
    move(460, 687);
    setVisible(false);

    ui->label->setProperty("mode","CounterpulsationPressure");
    ui->Help_Button->setProperty("mode","Help_Button");
    ui->Model_Label->setText("40cc ");
    ui->Model_Label->setProperty("mode","20px,colour4,255,255");
    // ui->Finish_Button->setProperty("mode","Finish_Button_False");
    ui->Gears_Label->setProperty("mode","First_Gear");
}

CounterpulsationPressure::~CounterpulsationPressure() {
    delete ui;
} 
