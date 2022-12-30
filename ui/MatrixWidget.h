#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <matrix/Matrix.h>
#include <QObject>
#include <QWidget>
#include <array>

class ItemStackedWidget;

using MatrixItemArray = std::array<ItemStackedWidget*, 81>;

class MatrixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixWidget(QWidget *parent = nullptr);

    void setValues(const Matrix&);
    void presetValues(const Matrix&, int number);

private:
    MatrixItemArray m_ItemArray;

signals:

};

#endif // MATRIXWIDGET_H
