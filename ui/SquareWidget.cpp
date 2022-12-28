#include "SquareWidget.h"
#include "ItemStackedWidget.h"
#include <QGridLayout>
#include "MatrixWidget.h"
#include "matrix/Matrix.h"


constexpr int SquareWidget::getItemIndex(int index, int col, int row) {
    int indCol = (index % 3) * 3 + col;
    int indRow = int(index / 3) * 3 + row;
    return Matrix::getIndex(indCol, indRow);
}


SquareWidget::SquareWidget(int index_, MatrixWidget *parent)
    : QWidget{parent}
    , index(index_)
{
    QGridLayout* layout = new QGridLayout(this);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            int itemIndex = getItemIndex(index, col, row);
            ItemStackedWidget* stack = new ItemStackedWidget(itemIndex, this);
            layout->addWidget(stack, row, col);
            m_Items.push_back(stack);
        }
    }
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
}
