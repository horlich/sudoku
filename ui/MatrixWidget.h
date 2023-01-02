#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <matrix/Matrix.h>
#include <QObject>
#include <QWidget>
#include <array>

class ItemStackedWidget;

using MatrixItemArray = std::array<ItemStackedWidget*, 81>;
using Difficulty = int;

class MatrixWidget : public QWidget
{
    Q_OBJECT
public:
    static constexpr Difficulty very_difficult {26};
    static constexpr Difficulty difficult      {28};
    static constexpr Difficulty medium         {30};
    static constexpr Difficulty easy           {32};
    static constexpr Difficulty very_easy      {34};

    explicit MatrixWidget(Difficulty, QWidget *parent = nullptr);

    void setValues(const Matrix&);
    void presetValues() const;

private:
    static std::set<int> getRandomIntegers(int number);

    MatrixItemArray m_ItemArray;
    Matrix m_Solution;
    Difficulty m_Difficulty = medium;
};

#endif // MATRIXWIDGET_H
