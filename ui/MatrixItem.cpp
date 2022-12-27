#include "MatrixItem.h"
#include "ItemStackedWidget.h"
#include "NumberEditor.h"
#include "oexception.h"

MatrixItem::MatrixItem(ItemStackedWidget* parent)
    : QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::Panel);
    QFont font;
    font.setPixelSize(30);
    font.setBold(true);
    setFont(font);
    setObjectName("Item");
    setStyleSheet("#Item { border: 1px solid #aaaaaa; }");
}
