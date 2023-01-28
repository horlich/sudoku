#include "NumberLabel.h"
#include "ItemStackedWidget.h"
#include "NumberEditor.h"
#include "oexception.h"



NumberLabel::NumberLabel(ItemStackedWidget* parent)
    : QLabel(parent)
    , m_Parent{parent}
{
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::NoFrame);
    QFont font;
    font.setPixelSize(30);
    font.setBold(true);
    setFont(font);
    setStyleSheet(ItemStackedWidget::blackWhite);
}


void NumberLabel::clear() {
    setText("");
    setStyleSheet(ItemStackedWidget::blackWhite);
}


void NumberLabel::redBackground(bool b) {
    b ? setStyleSheet(ItemStackedWidget::blackRed) : setStyleSheet(ItemStackedWidget::blackWhite);
}


void NumberLabel::mousePressEvent(QMouseEvent* event) {
    event->accept();
    if (event->button() == Qt::MouseButton::LeftButton) {
        m_Parent->onNumberLabelClicked();
    }
}
