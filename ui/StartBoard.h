#ifndef STARTBOARD_H
#define STARTBOARD_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include "Sudoku.h"

class GameBoard;
class StartBoard;


class SelectDifficultyWidget : public QWidget {
public:
    SelectDifficultyWidget(StartBoard* parent);

    Sudoku::Difficulty selectedDifficulty();

private:
    QComboBox* m_ComboBox;
};



class StartGameButton : public QPushButton
{
public:
    StartGameButton(StartBoard* parent);
};



class StartBoard : public QWidget
{
    Q_OBJECT
public:
    explicit StartBoard(GameBoard *parent);

signals:
    void startGameClicked(Sudoku::Difficulty);

protected:
    void onStartGameButtonClicked();

private:
    SelectDifficultyWidget* m_SelectWidget = nullptr;
    StartGameButton* m_StartButton = nullptr;
};

#endif // STARTBOARD_H
