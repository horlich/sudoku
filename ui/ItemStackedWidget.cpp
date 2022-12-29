#include "ItemStackedWidget.h"
#include "SquareWidget.h"
#include "NumberLabel.h"
#include "NumberEditor.h"

ItemStackedWidget::ItemStackedWidget(int index_, SquareWidget* parent)
    : QStackedWidget(parent)
    , index(index_)
    , m_NumberLabel(new NumberLabel(this))
    , m_NumberEditor(new NumberEditor(this))
{
    setFixedSize(side, side);
    setStyleSheet("ItemStackedWidget { border: 1px solid #aaaaaa; }");
    addWidget(m_NumberLabel);
    addWidget(m_NumberEditor);
    setCurrentIndex(0);
    connect(m_NumberEditor, &NumberEditor::finalNumberSelected, this, &ItemStackedWidget::onFinalNumberSelected);
}


void ItemStackedWidget::setFinalNumber(int i) const {
    m_NumberLabel->setText(QString(i + '0'));
}


void ItemStackedWidget::enterEvent(QEvent* ev) {
    ev->accept();
    setCurrentIndex(1);
}


void ItemStackedWidget::leaveEvent(QEvent* ev) {
    ev->accept();
    setCurrentIndex(0);
}


void ItemStackedWidget::onFinalNumberSelected(int i) const {
    setFinalNumber(i+1);
}
