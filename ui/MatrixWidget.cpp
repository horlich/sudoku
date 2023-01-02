#include "MatrixWidget.h"
#include "ItemStackedWidget.h"
#include "SquareWidget.h"
#include "onumber.h"
#include <QGridLayout>
#include <QtCore>
#include <set>


const QColor mainframe_color = QColor(234,16,133);


MatrixWidget::MatrixWidget(Difficulty diff, QWidget *parent)
    : QWidget{parent}
    , m_Difficulty(diff)
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
    m_Solution.populate();
    presetRandomValues();
}


void MatrixWidget::setValues(const Matrix& matrix) {
    const PositionVec& positions = matrix.positions();
    for (size_t i = 0; i < positions.size(); ++i) {
        ItemStackedWidget* item = m_ItemArray.at(i);
        item->setFinalNumber(positions.at(i)->value().toInt());
    }
}


std::set<int> MatrixWidget::getRandomIntegers(int number) {
    static ONumber::IntGenerator gen(0, 80);
    std::set<int> iset;
    while (iset.size() < number) {
        iset.insert(gen());
    }
    return iset;
}


void MatrixWidget::presetRandomValues() {
    const PositionVec& positions = m_Solution.positions();
    std::set<int> vs = getRandomIntegers(m_Difficulty);
    for (auto it = vs.begin(); it != vs.end(); ++it) {
        int index = *it;
        ItemStackedWidget* item = m_ItemArray.at(index);
        item->setLockedNumber(positions.at(index)->value().toInt());
    }
}
