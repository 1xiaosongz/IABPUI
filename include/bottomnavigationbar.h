//
// Created by Administrator on 2026/3/31.
//

#ifndef IABPUI_BOTTOMNAVIGATIONBAR_H
#define IABPUI_BOTTOMNAVIGATIONBAR_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class BottomNavigationBar;
}

QT_END_NAMESPACE

class BottomNavigationBar : public QWidget {
    Q_OBJECT

public:
    explicit BottomNavigationBar(QWidget *parent = nullptr);

    ~BottomNavigationBar() override;
    void refreshStyle(QWidget* w);


private slots:


private:

    Ui::BottomNavigationBar *ui;
};


#endif //IABPUI_BOTTOMNAVIGATIONBAR_H