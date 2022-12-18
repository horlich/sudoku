#include "MatrixItem.h"
#include "SquareWidget.h"
#include "oexception.h"

MatrixItem::MatrixItem(int index_, QWidget* parent)
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
//    qDebug() << "Moved:" << event->localPos();
}

SquareWidget* MatrixItem::getSquareWidget() const {
    SquareWidget* ret = dynamic_cast<SquareWidget*>(parent());
    if (! ret)
        throw OException::NullPointerException(Q_FUNC_INFO, "Parent is no SquareWidget");
    return ret;
}
