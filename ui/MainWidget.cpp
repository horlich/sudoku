#include "MainWidget.h"
#include "GameBoard.h"
#include "NavigationWidget.h"
#include <QHBoxLayout>
#include "Sudoku.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
    , m_NavigationWidget{new NavigationWidget{this}}
    , m_GameBoard{new GameBoard{this}}
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_NavigationWidget);
    mainLayout->addWidget(m_GameBoard);
}


void MainWidget::displayStartBoard()
{
    m_GameBoard->showStartBoard();
}
