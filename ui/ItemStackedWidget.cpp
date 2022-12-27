#include "ItemStackedWidget.h"
#include "SquareWidget.h"
#include "MatrixItem.h"

ItemStackedWidget::ItemStackedWidget(int index_, SquareWidget* parent)
    : QStackedWidget(parent)
    , index(index_)
    , m_MatrixItem(new MatrixItem(this))
{
    setFixedSize(side, side);
    addWidget(m_MatrixItem);
}


void ItemStackedWidget::setFinalNumber(int i) const {
    m_MatrixItem->setText(QString(i + '0'));
}


void ItemStackedWidget::enterEvent(QEvent* ev) {
    ev->accept();
    qDebug() << "ENTER Index" << index;
}


void ItemStackedWidget::leaveEvent(QEvent* ev) {
    ev->accept();
    qDebug() << "LEAVE Index" << index;
}
