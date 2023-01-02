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
    presetValues();
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


void MatrixWidget::presetValues() const
{
    Matrix newMatrix;
    static constexpr int random_start_values {5};
    std::set<int> vs = getRandomIntegers(random_start_values);
    for (int index : vs) {
        int val = m_Solution.position(index)->value().toInt();
        newMatrix.presetValue(index, val);
        ItemStackedWidget* item = m_ItemArray.at(index);
        item->setLockedNumber(val);
    }
    int totalSet = random_start_values;
    for (int alternatives = 9; alternatives > 0; --alternatives) {
        for (int index = 0; index < 80; ++index) {
            MatrixPosition* mpSolution = m_Solution.position(index);
            MatrixPosition* mpNew = newMatrix.position(index);
            if (mpNew->value().isValid()) continue; // we need empty positions!
            int count = mpNew->countAlternatives();
            if (count >= alternatives) {
                int presetVal = mpSolution->value().toInt();
                newMatrix.presetValue(index, presetVal);
                ItemStackedWidget* item = m_ItemArray.at(index);
                item->setLockedNumber(presetVal);
                if (++totalSet >= m_Difficulty) return;
            }
        }
    }
}
