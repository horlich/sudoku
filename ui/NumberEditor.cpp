#include "NumberEditor.h"
#include "ItemStackedWidget.h"
#include <QLabel>
#include <QGridLayout>
#include <QEvent>
#include <QMouseEvent>
#include <array>
#include <QDebug>
#include <QTimer>




//---------------------/ TrialNumberItem /----------------------//


TrialNumberItem::TrialNumberItem(int index_, NumberEditor* parent)
    : QLabel(parent)
    , index(index_)
    , m_Parent(parent)
    , m_Timer(new QTimer(this))
{
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::NoFrame);
    QFont font;
    font.setPixelSize(font_pixel_size);
    setFont(font);
    m_Timer->setSingleShot(true);
    m_Timer->setInterval(200);
    connect(m_Timer, &QTimer::timeout, this, &TrialNumberItem::singleClick);
}


void TrialNumberItem::setMarked(bool b) {
    if (b) {
        setStyleSheet("color: white; background-color: black");
    } else {
        setStyleSheet("");
    }
}


void TrialNumberItem::enterEvent(QEvent* ev) {
    ev->accept();
    setMarked(true);
}


void TrialNumberItem::leaveEvent(QEvent* ev) {
    ev->accept();
    if (! selected)
        setMarked(false);
}


void TrialNumberItem::mouseDoubleClickEvent(QMouseEvent *event) {
    m_Timer->stop();
    if (event->button() == Qt::MouseButton::LeftButton) {
        m_Parent->clearNumbers();
        emit m_Parent->finalNumberSelected(index+1);
    }
}


void TrialNumberItem::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::MouseButton::LeftButton) {
        m_Timer->start();
    }
}


void TrialNumberItem::singleClick() const {
    m_Parent->onNumberSelected(index);
}



//---------------------/ NumberEditor /----------------------//


NumberEditor::NumberEditor(ItemStackedWidget *parent)
    : QFrame{parent}
{
    QGridLayout* layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    int index = 0;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            TrialNumberItem* item = new TrialNumberItem(index++, this);
            layout->addWidget(item, row, col);
            m_Items[item->index] = item;
        }
    }
}


void NumberEditor::onNumberSelected(int index) {
    TrialNumberItem* item = m_Items.at(index);
    if (item->selected) {
        item->selected = false;
    } else {
        item->selected = true;
    }
    emit trialNumberSelected();
}


void NumberEditor::clearNumbers() {
    for (TrialNumberItem* item : m_Items) {
        item->clear();
        item->selected = false;
    }
}


void NumberEditor::showAllNumbers(bool markSelected) const {
    for (TrialNumberItem* item : m_Items) {
        item->showText();
        if (markSelected && item->selected)
            item->setMarked(true);
    }
}


void NumberEditor::showSelectedNumbers() {
    for (TrialNumberItem* item : m_Items) {
        item->setMarked(false);
        if (item->selected) {
            item->showText();
        } else {
            item->clear();
        }
    }
}
