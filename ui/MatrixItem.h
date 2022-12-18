#ifndef MATRIXITEM_H
#define MATRIXITEM_H


#include <QtCore>
#include <QLabel>
#include <QMouseEvent>

class SquareWidget;

class MatrixItem : public QLabel
{
    Q_OBJECT
public:
    static constexpr int side {50};
    MatrixItem(int index, QWidget* parent);

    int index;

protected:
    void mouseMoveEvent(QMouseEvent*) override;

private:
    SquareWidget* getSquareWidget() const;
};

#endif // MATRIXITEM_H
