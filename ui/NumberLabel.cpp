#include "NumberLabel.h"
#include "ItemStackedWidget.h"
#include "NumberEditor.h"
#include "oexception.h"



NumberLabel::NumberLabel(ItemStackedWidget* parent)
    : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::NoFrame);
    QFont font;
    font.setPixelSize(30);
    font.setBold(true);
    setFont(font);
    setStyleSheet("color: black; background-color: white");
}


void NumberLabel::clear() {
    setText("");
}


void NumberLabel::mousePressEvent(QMouseEvent* event) {
    event->accept();
    if (event->button() == Qt::MouseButton::LeftButton) {
        emit singleClicked();
    }
}
