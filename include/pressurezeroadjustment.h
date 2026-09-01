#ifndef IABP_UI_PRESSUREZEROADJUSTMENT_H
#define IABP_UI_PRESSUREZEROADJUSTMENT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class PressureZeroAdjustment;
}
QT_END_NAMESPACE

class PressureZeroAdjustment : public QWidget
{
    Q_OBJECT

public:
    explicit PressureZeroAdjustment(QWidget* parent = nullptr);
    ~PressureZeroAdjustment() override;
    bool isAffirmSelected() const;
    void resetSelection();
    void setSubmitting(bool submitting);

signals:
    void finishClicked();
    void helpClicked();

private:
    enum class Selection
    {
        Affirm,
        Cancel
    };

    void setSelection(Selection selection);
    void refreshStyle(QWidget* widget);

    Ui::PressureZeroAdjustment* ui;
    Selection m_selection = Selection::Cancel;
};

#endif // IABP_UI_PRESSUREZEROADJUSTMENT_H
