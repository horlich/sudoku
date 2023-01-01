#ifndef NUMBEREDITOR_H
#define NUMBEREDITOR_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <set>

class ItemStackedWidget;
class NumberEditor;


class TrialNumberItem : public QLabel {
public:
    static constexpr int font_pixel_size {15};

    explicit TrialNumberItem(int index, NumberEditor* parent);

    inline void clear() { setText(""); }
    inline void showText() { setText(QString(index + '1')); }
    void setMarked(bool);
    void singleClick() const;

    int index;
    bool selected = false;

protected:
    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;
    void mouseDoubleClickEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;

private:
    NumberEditor* m_Parent;
    QTimer* m_Timer;
};



using TrialItemArray = std::array<TrialNumberItem*, 9>;



class NumberEditor : public QFrame
{
    Q_OBJECT

public:
    explicit NumberEditor(ItemStackedWidget *parent = nullptr);

    void clearNumbers();
    void showAllNumbers(bool markSelected) const;
    void showSelectedNumbers();
    void onNumberSelected(int index);
//    void markSelectedNumbers() const;

signals:
    void finalNumberSelected(int);
    void trialNumberSelected();

private:
    TrialItemArray m_Items;
};

#endif // NUMBEREDITOR_H
