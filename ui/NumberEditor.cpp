#include "NumberEditor.h"
#include "ItemStackedWidget.h"
#include <QLabel>
#include <QGridLayout>
#include <QEvent>
#include <QMouseEvent>



class TrialNumberItem : public QLabel {
public:
    explicit TrialNumberItem(int index, NumberEditor* parent);

protected:
    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;
    void mouseDoubleClickEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

    int index;

private:
    NumberEditor* m_Parent;
};


TrialNumberItem::TrialNumberItem(int index_, NumberEditor* parent)
    : QLabel(parent)
    , index(index_)
    , m_Parent(parent)
{
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::NoFrame);
    QFont font;
    font.setPixelSize(14);
    setFont(font);
    setText(QString(index + '1'));
//    setStyleSheet(ItemStackedWidget::styleSheetCommand("black", ItemStackedWidget::backgroundGrey));
    setStyleSheet(ItemStackedWidget::blackGrey);
}


void TrialNumberItem::enterEvent(QEvent* ev) {
    ev->accept();
    setStyleSheet("color: white; background-color: black");
}


void TrialNumberItem::leaveEvent(QEvent* ev) {
    ev->accept();
    setStyleSheet(ItemStackedWidget::blackGrey);
}


void TrialNumberItem::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        emit m_Parent->finalNumberSelected(index);
    }
}


void TrialNumberItem::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        emit m_Parent->trialNumberSelected(index);
    }
}


NumberEditor::NumberEditor(ItemStackedWidget *parent)
    : QFrame{parent}
{
    QGridLayout* layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    int index = 0;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            layout->addWidget(new TrialNumberItem(index++, this), row, col);
        }
    }
    setStyleSheet("background-color: '#aaaaaa'");
}
