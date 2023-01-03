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
                connect(item, &ItemStackedWidget::numberLabelChanged, this, &MatrixWidget::onNumberLabelChanged);
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


void MatrixWidget::setValues(const Matrix& matrix)
{
    const PositionVec& positions = matrix.positions();
    for (size_t i = 0; i < positions.size(); ++i) {
        ItemStackedWidget* item = m_ItemArray.at(i);
        item->setFinalNumber(positions.at(i)->value().toInt());
    }
}


std::set<int> MatrixWidget::getRandomIntegers(int number)
{
    static ONumber::IntGenerator gen(0, 80);
    std::set<int> iset;
    while (iset.size() < number) {
        iset.insert(gen());
    }
    return iset;
}


void MatrixWidget::presetValue(int index)
{
    int val = m_Solution.position(index)->value().toInt();
    m_Workpiece.presetValue(index, val);
    ItemStackedWidget* item = m_ItemArray.at(index);
    item->setLockedNumber(val);
}


void MatrixWidget::presetValues()
{
    static constexpr int random_start_values {5};
    std::set<int> vs = getRandomIntegers(random_start_values);
    for (int index : vs)
        presetValue(index);
    int totalSet = random_start_values;
    for (int alternatives = 9; alternatives > 0; --alternatives) {
        for (int index = 0; index < 80; ++index) {
            MatrixPosition* mpNew = m_Workpiece.position(index);
            if (mpNew->value().isValid()) continue; // we need empty positions!
            int count = mpNew->countAlternatives();
            if (count >= alternatives) {
                presetValue(index);
                if (++totalSet >= m_Difficulty) return;
            }
        }
    }
}


void MatrixWidget::onNumberLabelChanged(int index, int val)
{
    m_Workpiece.setValue(index, val);
}
