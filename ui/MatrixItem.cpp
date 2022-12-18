#include "MatrixItem.h"
#include "SquareWidget.h"
#include "oexception.h"

MatrixItem::MatrixItem(int index_, SquareWidget* parent)
    : QLabel(parent)
    , index(index_)
{
    setText(QString::number(index));
    setFixedSize(side, side);
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::Panel);
    QFont font;
    font.setPixelSize(30);
    font.setBold(true);
    setFont(font);
    setObjectName("Item");
    setStyleSheet("#Item { border: 1px solid #aaaaaa; }");
    setMouseTracking(true);
}

void MatrixItem::mouseMoveEvent(QMouseEvent * event) {
    if (! m_IsActive)
        mouseGained();
}

SquareWidget* MatrixItem::getSquareWidget() const {
    SquareWidget* ret = dynamic_cast<SquareWidget*>(parent());
    if (! ret)
        throw OException::NullPointerException(Q_FUNC_INFO, "Parent is no SquareWidget");
    return ret;
}


void MatrixItem::mouseLost() {
    m_IsActive = false;
    qDebug() << "Mouse lost";
}


void MatrixItem::mouseGained() {
    m_IsActive = true;
    SquareWidget* mySquareWidget = getSquareWidget();
    if (mySquareWidget->activeItem && (mySquareWidget->activeItem != this))
        mySquareWidget->activeItem->mouseLost();
    mySquareWidget->activeItem = this;
    qDebug() << "Mouse gained";
}
