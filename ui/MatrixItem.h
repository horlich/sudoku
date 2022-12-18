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
    MatrixItem(int index, SquareWidget* parent);

    void mouseLost();

    int index;

protected:
    void mouseMoveEvent(QMouseEvent*) override;

private:
    void mouseGained();
    SquareWidget* getSquareWidget() const;

    bool m_IsActive = false;
};

#endif // MATRIXITEM_H
