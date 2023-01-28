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
//    int getNumber() const;
    void clear();
    void redBackground();

protected:
    void mousePressEvent(QMouseEvent*) override;

signals:

private:
    ItemStackedWidget* m_Parent;
};

#endif // MATRIXITEM_H
