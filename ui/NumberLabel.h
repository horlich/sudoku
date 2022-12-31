#ifndef MATRIXITEM_H
#define MATRIXITEM_H


#include <QtCore>
#include <QLabel>
#include <QMouseEvent>

class ItemStackedWidget;

class NumberLabel : public QLabel
{
    Q_OBJECT
public:
    NumberLabel(ItemStackedWidget* parent);

    void clear();


protected:

private:
};

#endif // MATRIXITEM_H
