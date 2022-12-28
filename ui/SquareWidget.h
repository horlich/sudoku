#ifndef SQUAREWIDGET_H
#define SQUAREWIDGET_H

#include <QWidget>
#include <vector>

class ItemStackedWidget;
class MatrixWidget;

class SquareWidget : public QWidget
{
    Q_OBJECT
public:
    static constexpr int getItemIndex(int index, int col, int row);

    explicit SquareWidget(int index, MatrixWidget *parent = nullptr);

    inline const std::vector<ItemStackedWidget*>& getItems() { return m_Items; }

    int index;

private:
    std::vector<ItemStackedWidget*> m_Items;

protected:

signals:

};

#endif // SQUAREWIDGET_H
