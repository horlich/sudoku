#include "MainWidget.h"
#include "GameBoard.h"
#include <QVBoxLayout>
#include "Sudoku.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new GameBoard(this));
}
