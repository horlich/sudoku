#include "ItemStackedWidget.h"
#include "SquareWidget.h"
#include "NumberLabel.h"
#include "NumberEditor.h"

constexpr int index_number_label  {0};
constexpr int index_number_editor {1};


QString ItemStackedWidget::styleSheetCommand(const QString& color, const QString& backgroundColor) {
    QString ret;
    QTextStream buf(&ret);
    buf << "color: " << color << "; background-color: " << backgroundColor << ";";
    return ret;
}


const QString ItemStackedWidget::blackGrey = ItemStackedWidget::styleSheetCommand("black", ItemStackedWidget::backgroundGrey);


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
    setCurrentIndex(index_number_label);
    connect(m_NumberEditor, &NumberEditor::finalNumberSelected, this, &ItemStackedWidget::onFinalNumberSelected);
}


ItemStackedWidget::State ItemStackedWidget::setState(State st) {
    if (st == m_State) return m_State;
    State oldState = m_State;
    m_State = st;
    return oldState;
}


void ItemStackedWidget::setFinalNumber(int i) {
    m_NumberLabel->setText(QString(i + '0'));
    setState(State::Final);
}


void ItemStackedWidget::setLockedNumber(int i) {
    m_NumberLabel->setText(QString(i + '0'));
    setState(State::Locked);
}


void ItemStackedWidget::enterEvent(QEvent* ev) {
    ev->accept();
    switch (m_State) {
    case State::Trial:
    case State::Empty:
        setCurrentIndex(index_number_editor);
        break;
    default:
        setCurrentIndex(index_number_label);
    }
}


void ItemStackedWidget::leaveEvent(QEvent* ev) {
    ev->accept();
    setCurrentIndex(index_number_label);
}


void ItemStackedWidget::onFinalNumberSelected(int i) {
    setFinalNumber(i+1);
}
