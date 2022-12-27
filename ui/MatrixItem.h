#ifndef MATRIXITEM_H
#define MATRIXITEM_H


#include <QtCore>
#include <QLabel>
#include <QMouseEvent>

class ItemStackedWidget;

class MatrixItem : public QLabel
{
    Q_OBJECT
public:
    MatrixItem(ItemStackedWidget* parent);


protected:

private:
};

#endif // MATRIXITEM_H
