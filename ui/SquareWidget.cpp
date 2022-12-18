#include "SquareWidget.h"
#include "MatrixItem.h"
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
            MatrixItem* mi = new MatrixItem(itemIndex, this);
            layout->addWidget(mi, row, col);
            m_MatrixItems.push_back(mi);
        }
    }
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    setMouseTracking(true);
}

void SquareWidget::mouseMoveEvent(QMouseEvent * event) {
//    qDebug() << "Moved:" << event->localPos();
    if (activeItem) {
        activeItem->mouseLost();
        activeItem = nullptr;
    }
}
