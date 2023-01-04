#include "MainWidget.h"
#include "MatrixWidget.h"
#include <QVBoxLayout>
#include "Sudoku.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new MatrixWidget(Sudoku::very_easy, this));
}
