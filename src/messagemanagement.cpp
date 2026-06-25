//
// Created by Administrator on 2026/4/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MessageManagement.h" resolved

#include "../include/messagemanagement.h"
#include "ui_MessageManagement.h"
#include <QMovie>

MessageManagement::MessageManagement(QWidget *parent) : QWidget(parent), ui(new Ui::MessageManagement) {
    ui->setupUi(this);
    move(68 , 68);
    setVisible(false);
    ui->scrollArea->setWidgetResizable(true);
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QPixmap backgroundPixmap(":/MessageManagement/Group 10568.png");
    if (!backgroundPixmap.isNull()) {
        ui->Label->setPixmap(backgroundPixmap.scaled(ui->Label->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        ui->Label->setScaledContents(true);
    }
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->Label->setProperty("mode","MessageManagement_Label");
    ui->Widget->setProperty("mode","MessageManagement_Widget");
    ui->Close_Button->setProperty("mode","Close_Button");
    ui->verticalLayout_2->setAlignment(Qt::AlignTop);
    QScroller::grabGesture(
        ui->scrollArea->viewport(),
        QScroller::LeftMouseButtonGesture
    );
}

MessageManagement::~MessageManagement() {
    delete ui;
}