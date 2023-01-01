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
const QString ItemStackedWidget::blackWhite = ItemStackedWidget::styleSheetCommand("black", "white");


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
    connect(m_NumberEditor, &NumberEditor::trialNumberSelected, this, &ItemStackedWidget::onTrialNumberSelected);
    connect(m_NumberLabel, &NumberLabel::singleClicked, this, &ItemStackedWidget::onNumberLabelClicked);
}


ItemStackedWidget::State ItemStackedWidget::setState(State st) {
    if (st == m_State) return m_State;
    State oldState = m_State;
    m_State = st;
    return oldState;
}


void ItemStackedWidget::onNumberLabelClicked() {
    if (m_State == State::Locked) return;
    m_NumberLabel->clear();
    setState(State::Trial);
    m_NumberEditor->showAllNumbers(false);
    setCurrentIndex(index_number_editor);
}


void ItemStackedWidget::setFinalNumber(int i) {
    m_NumberLabel->setText(QString(i + '0'));
    setCurrentIndex(index_number_label);
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
        m_NumberEditor->showAllNumbers(true);
        m_NumberEditor->setStyleSheet(ItemStackedWidget::blackGrey);
        setCurrentIndex(index_number_editor);
        break;
    case State::Final:
        setCurrentIndex(index_number_label);
        m_NumberLabel->setStyleSheet(blackGrey);
        break;
    default:
        setCurrentIndex(index_number_label);
    }
}


void ItemStackedWidget::leaveEvent(QEvent* ev) {
    ev->accept();
    switch (m_State) {
    case (State::Trial):
        m_NumberEditor->showSelectedNumbers();
        setCurrentIndex(index_number_editor);
        m_NumberEditor->setStyleSheet(blackWhite);
        break;
    default:
        setCurrentIndex(index_number_label);
        m_NumberLabel->setStyleSheet(blackWhite);
    }
}


void ItemStackedWidget::onFinalNumberSelected(int i) {
    setFinalNumber(i);
}


void ItemStackedWidget::onTrialNumberSelected() {
    setState(State::Trial);
}
