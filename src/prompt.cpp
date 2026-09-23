//
// Created by Administrator on 2026/9/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Prompt.h" resolved

#include "prompt.h"
#include "ui_Prompt.h"


Prompt::Prompt(QWidget *parent) : QWidget(parent), ui(new Ui::Prompt) {
    ui->setupUi(this);
    move(705, 330);
    setVisible(false);


    ui->label->setProperty("mode","Prompt_label");
    ui->Prompt_Label_1->setProperty("mode","20px,colour255,255,255,LeftVCenter");
    ui->Prompt_Label_2->setProperty("mode","20px,colour255,255,255,LeftVCenter");
    ui->Prompt_Label_3->setProperty("mode","20px,colour255,255,255,LeftVCenter");
    ui->Prompt_Label_2->setText("自检完成");
    ui->Prompt_Label_1->setText("自检完成");
    ui->Prompt_Label_3->setText("电池正在使用");
}

Prompt::~Prompt() {
    delete ui;
}
