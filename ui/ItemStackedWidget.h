#ifndef ITEMSTACKEDWIDGET_H
#define ITEMSTACKEDWIDGET_H

#include <QStackedWidget>

class SquareWidget;
class MatrixItem;

class ItemStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    static constexpr int side {50};

    ItemStackedWidget(int index, SquareWidget* parent);

    void setFinalNumber(int) const;

    int index;

protected:
    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;

private:
    MatrixItem* m_MatrixItem = nullptr;
};

#endif // ITEMSTACKEDWIDGET_H
