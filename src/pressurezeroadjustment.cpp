#include "pressurezeroadjustment.h"
#include "ui_pressurezeroadjustment.h"

#include <QPushButton>
#include <QStyle>

PressureZeroAdjustment::PressureZeroAdjustment(QWidget* parent)
    : QWidget(parent),
      ui(new Ui::PressureZeroAdjustment)
{
    ui->setupUi(this);
    move(900, 714);
    setVisible(false);
    ui->Label->setProperty("mode", "PressureZeroAdjustment_Label");
    ui->Help_Button->setProperty("mode", "Help_Button");
    ui->Finish_Button->setProperty("mode", "PressureZeroAdjustment_Finish_Button");
    ui->Affirm_Label->setText(QStringLiteral("确认调零"));
    ui->Cancel_Label->setText(QStringLiteral("取消调零"));

    resetSelection();
    refreshStyle(ui->Label);
    refreshStyle(ui->Help_Button);
    refreshStyle(ui->Finish_Button);

    connect(ui->Affirm_Button, &QPushButton::clicked, this, [this]() {
        setSelection(Selection::Affirm);
    });
    connect(ui->Cancel_Button, &QPushButton::clicked, this, [this]() {
        setSelection(Selection::Cancel);
    });
    connect(ui->Finish_Button, &QPushButton::clicked, this, &PressureZeroAdjustment::finishClicked);
    connect(ui->Help_Button, &QPushButton::clicked, this, &PressureZeroAdjustment::helpClicked);
}

PressureZeroAdjustment::~PressureZeroAdjustment()
{
    delete ui;
}

bool PressureZeroAdjustment::isAffirmSelected() const
{
    return m_selection == Selection::Affirm;
}

void PressureZeroAdjustment::resetSelection()
{
    setSelection(Selection::Cancel);
}

void PressureZeroAdjustment::setSubmitting(bool submitting)
{
    ui->Affirm_Button->setEnabled(!submitting);
    ui->Cancel_Button->setEnabled(!submitting);
    ui->Finish_Button->setEnabled(!submitting);
}

void PressureZeroAdjustment::setSelection(Selection selection)
{
    m_selection = selection;

    const bool affirmActive = selection == Selection::Affirm;
    ui->Affirm_Backdrop->setProperty("mode", affirmActive ? "Affirm_Backdrop_True"
                                                          : "Affirm_Backdrop_False");
    ui->Cancel_Backdrop->setProperty("mode", affirmActive ? "Cancel_Backdrop_False"
                                                          : "Cancel_Backdrop_True");
    ui->Affirm_Label->setProperty("mode", affirmActive ? "40px,colour4,255,255,AlignCenter"
                                                       : "40px,colour255,255,255,AlignCenter");
    ui->Cancel_Label->setProperty("mode", affirmActive ? "40px,colour255,255,255,AlignCenter"
                                                       : "40px,colour4,255,255,AlignCenter");

    refreshStyle(ui->Affirm_Backdrop);
    refreshStyle(ui->Cancel_Backdrop);
    refreshStyle(ui->Affirm_Label);
    refreshStyle(ui->Cancel_Label);
}

void PressureZeroAdjustment::refreshStyle(QWidget* widget)
{
    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
    widget->update();
}
