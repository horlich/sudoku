#include "MatrixWidget.h"
#include "MatrixItem.h"
#include "SquareWidget.h"
#include <QGridLayout>
#include <QtCore>

const QColor mainframe_color = QColor(234,16,133);

MatrixWidget::MatrixWidget(QWidget *parent)
    : QWidget{parent}
{
    int index = 0;
    QGridLayout* layout = new QGridLayout(this);
    layout->setSpacing(2);
    layout->setContentsMargins(3,3,3,3);
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            SquareWidget* sw = new SquareWidget(index++, this);
            layout->addWidget(sw, row, col);
            for (MatrixItem* item : sw->getItems()) {
                m_ItemArray.at(item->index) = item;
            }
        }
    }
    QPalette palette;
//    palette.setColor(QPalette::Window, Qt::black);
    palette.setColor(QPalette::Window, mainframe_color);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    Matrix matrix;
    matrix.populate();
    setValues(matrix);
}



void MatrixWidget::setValues(const Matrix& matrix) {
    const PositionVec& positions = matrix.positions();
    for (size_t i = 0; i < positions.size(); ++i) {
        MatrixItem* item = m_ItemArray.at(i);
        item->setText(QString::number(positions.at(i)->value().toInt()));
    }
}
