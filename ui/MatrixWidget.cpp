#include "MatrixWidget.h"
#include "ItemStackedWidget.h"
#include "SquareWidget.h"
#include "onumber.h"
#include <QGridLayout>
#include <QtCore>
#include <set>


const QColor mainframe_color = QColor(234,16,133);


MatrixWidget::MatrixWidget(Difficulty, QWidget *parent)
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
            for (ItemStackedWidget* item : sw->getItems()) {
                m_ItemArray.at(item->index) = item;
            }
        }
    }
    QPalette palette;
    palette.setColor(QPalette::Window, mainframe_color);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    Matrix matrix;
    matrix.populate();
    presetValues(matrix, 30);
}


void MatrixWidget::setValues(const Matrix& matrix) {
    const PositionVec& positions = matrix.positions();
    for (size_t i = 0; i < positions.size(); ++i) {
        ItemStackedWidget* item = m_ItemArray.at(i);
        item->setFinalNumber(positions.at(i)->value().toInt());
    }
}


void MatrixWidget::presetValues(const Matrix& matrix, int number) {
    const PositionVec& positions = matrix.positions();
    std::set<int> vs;
    ONumber::IntGenerator gen(0, 80);
    while (vs.size() < number) {
        vs.insert(gen());
    }
    for (auto it = vs.begin(); it != vs.end(); ++it) {
        int index = *it;
        ItemStackedWidget* item = m_ItemArray.at(index);
        item->setLockedNumber(positions.at(index)->value().toInt());

    }
}
