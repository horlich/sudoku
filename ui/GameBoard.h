#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QStackedWidget>
#include <QObject>
#include "Sudoku.h"

class MainWidget;
class MatrixWidget;
class StartBoard;

class GameBoard : public QStackedWidget
{
    Q_OBJECT
public:
    GameBoard(MainWidget* parent);

private:
    void onStartGameClicked(Sudoku::Difficulty);

    StartBoard* m_StartBoard = nullptr;
    MatrixWidget* m_MatrixWidget = nullptr;
};

#endif // GAMEBOARD_H
