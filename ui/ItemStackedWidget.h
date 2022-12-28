#ifndef ITEMSTACKEDWIDGET_H
#define ITEMSTACKEDWIDGET_H

#include <QStackedWidget>

class SquareWidget;
class NumberLabel;
class NumberEditor;

class ItemStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    static constexpr int side {60};  // must be divisible by 3

    ItemStackedWidget(int index, SquareWidget* parent);

    void setFinalNumber(int) const;

    int index;

protected:
    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;

private:
    NumberLabel* m_NumberLabel = nullptr;
    NumberEditor* m_NumberEditor = nullptr;
};

#endif // ITEMSTACKEDWIDGET_H
