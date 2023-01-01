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
    void mousePressEvent(QMouseEvent*) override;

signals:
    void singleClicked();
};

#endif // MATRIXITEM_H
