#ifndef SQUAREWIDGET_H
#define SQUAREWIDGET_H

#include <QWidget>
#include <vector>

class MatrixItem;

class SquareWidget : public QWidget
{
    Q_OBJECT
public:
    static constexpr int getItemIndex(int index, int col, int row);

    explicit SquareWidget(int index, QWidget *parent = nullptr);

    inline const std::vector<MatrixItem*>& getItems() { return m_MatrixItems; }

    int index;
    MatrixItem* activeItem = nullptr;

private:
    std::vector<MatrixItem*> m_MatrixItems;

protected:
    void mouseMoveEvent(QMouseEvent*) override;

signals:

};

#endif // SQUAREWIDGET_H
