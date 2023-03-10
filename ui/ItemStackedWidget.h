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
    static constexpr int side {60};
    static constexpr char backgroundGrey[] {"#DDDDDD"};
    static const QString blackGrey;
    static const QString blackWhite;
    static const QString blackRed;

    enum class State { Empty, Locked, Trial, Final };
    enum class CheckedState {Unchecked, Right, Wrong};

    static QString styleSheetCommand(const QString& color, const QString& backgroundColor);

    ItemStackedWidget(int index, SquareWidget* parent);

    void setFinalNumber(int);
    void setLockedNumber(int);
    void onFinalNumberSelected(int);
    void onTrialNumberSelected();
    State setState(State);  // returns old state
    void clear();
    void redLabel(bool = true);
    void onNumberLabelClicked();

    int index;

protected:
    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;

private:
    void setNumberLabel(int);

    NumberLabel* m_NumberLabel = nullptr;
    NumberEditor* m_NumberEditor = nullptr;
    State m_State { State::Empty };
    CheckedState m_CheckedState = CheckedState::Unchecked;

signals:
    void numberLabelChanged(int index, int newVal);
};

#endif // ITEMSTACKEDWIDGET_H
