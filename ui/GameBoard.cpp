#include "GameBoard.h"
#include "MainWidget.h"
#include "MatrixWidget.h"
#include "StartBoard.h"
#include <QLayout>
#include <QDebug>

constexpr int index_start_board {0};
constexpr int index_matrix_widget {1};


GameBoard::GameBoard(MainWidget* parent)
    : QStackedWidget(parent)
    , m_StartBoard{new StartBoard(this)}
    , m_MatrixWidget{new MatrixWidget(this)}
{
    addWidget(m_StartBoard);
    addWidget(m_MatrixWidget);
    setCurrentIndex(index_start_board);
    connect(m_StartBoard, &StartBoard::startGameClicked, this, &GameBoard::onStartGameClicked);
}


void GameBoard::onStartGameClicked(Sudoku::Difficulty diff) {
    m_MatrixWidget->startNewGame(diff);
    setCurrentIndex(index_matrix_widget);
}


void GameBoard::showStartBoard()
{
    setCurrentIndex(index_start_board);
}


void GameBoard::checkNumbers()
{
    m_MatrixWidget->checkNumbers();
}
