//
// Created by Administrator on 2026/9/10.
//

#ifndef IABPUI_PROMPT_H
#define IABPUI_PROMPT_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Prompt;
}

QT_END_NAMESPACE

class Prompt : public QWidget {
    Q_OBJECT

public:
    explicit Prompt(QWidget *parent = nullptr);

    ~Prompt() override;

private:
    Ui::Prompt *ui;
};


#endif //IABPUI_PROMPT_H
