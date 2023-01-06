#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <matrix/Matrix.h>
#include <QObject>
#include <QWidget>
#include <array>
#include "Sudoku.h"

class ItemStackedWidget;

using Sudoku::Difficulty;

class MatrixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixWidget(QWidget *parent = nullptr);
    void onNumberLabelChanged(int index, int val);
    void startNewGame(Difficulty);

private:
    static std::set<int> getRandomIntegers(int number);

    void setValues(const Matrix&);
    void presetValue(int index);  // set a locked value into m_Workspace
    void presetValues(Difficulty);

    Sudoku::MatrixItemArray m_ItemArray;
    Matrix m_Solution;
    Matrix m_Workpiece;
//    Difficulty m_Difficulty = Sudoku::moderate;
};

#endif // MATRIXWIDGET_H
