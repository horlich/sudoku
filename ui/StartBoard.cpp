#include "StartBoard.h"
#include "GameBoard.h"
#include <QVBoxLayout>
#include <QFormLayout>


SelectDifficultyWidget::SelectDifficultyWidget(StartBoard* parent)
    : QWidget{parent}
    , m_ComboBox{new QComboBox(this)}
{
    m_ComboBox->addItem("Sehr leicht", QVariant(Sudoku::very_easy));
    m_ComboBox->addItem("Leicht", QVariant(Sudoku::easy));
    m_ComboBox->addItem("Mittelschwer", QVariant(Sudoku::moderate));
    m_ComboBox->addItem("Schwer", QVariant(Sudoku::difficult));
    m_ComboBox->addItem("Sehr schwer", QVariant(Sudoku::very_difficult));
    QFormLayout* layout = new QFormLayout(this);
    layout->addRow("Schwierigkeit:", m_ComboBox);
}


Sudoku::Difficulty SelectDifficultyWidget::selectedDifficulty() {
    return m_ComboBox->currentData().toInt();
}


StartGameButton::StartGameButton(StartBoard* parent)
    : QPushButton(parent)
{
    setText("Spiel beginnen");
}


StartBoard::StartBoard(GameBoard *parent)
    : QWidget{parent}
    , m_SelectWidget{new SelectDifficultyWidget{this}}
    , m_StartButton{new StartGameButton{this}}
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_SelectWidget, 0, Qt::AlignCenter);
    layout->addWidget(m_StartButton, 0, Qt::AlignCenter);
    connect(m_StartButton, &QPushButton::clicked, this, &StartBoard::onStartGameButtonClicked);
}


void StartBoard::onStartGameButtonClicked() {
    emit startGameClicked(m_SelectWidget->selectedDifficulty());
}
