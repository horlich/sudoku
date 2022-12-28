#include "NumberEditor.h"
#include "ItemStackedWidget.h"
#include <QLabel>
#include <QGridLayout>

class TrialNumberItem : public QLabel {
public:
    explicit TrialNumberItem(int index, NumberEditor* parent);

    int index;
};


TrialNumberItem::TrialNumberItem(int index_, NumberEditor* parent)
    : QLabel(parent)
    , index(index_)
{
    setAlignment(Qt::AlignCenter);
    setFrameShape(QFrame::NoFrame);
    QFont font;
    font.setPixelSize(12);
    setFont(font);
    setText(QString(index + '1'));
}


NumberEditor::NumberEditor(ItemStackedWidget *parent)
    : QFrame{parent}
{
    QGridLayout* layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(2,2,2,2);
    int index = 0;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            layout->addWidget(new TrialNumberItem(index++, this), row, col);
        }
    }
}
