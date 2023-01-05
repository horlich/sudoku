#include "GameBoard.h"
#include "MainWidget.h"
#include "MatrixWidget.h"
#include "Sudoku.h"
#include "StartBoard.h"

constexpr int index_start_board {0};
constexpr int index_matrix_widget {1};


GameBoard::GameBoard(MainWidget* parent)
    : QStackedWidget(parent)
    , m_StartBoard{new StartBoard(this)}
    , m_MatrixWidget{new MatrixWidget(Sudoku::very_easy, this)}
{
    addWidget(m_StartBoard);
    addWidget(m_MatrixWidget);
    setCurrentIndex(index_start_board);
}
