#ifndef NUMBEREDITOR_H
#define NUMBEREDITOR_H

#include <QObject>
#include <QWidget>

class MatrixItem;

class NumberEditor : public QWidget
{
    Q_OBJECT
public:
    explicit NumberEditor(MatrixItem *parent = nullptr);

signals:

};

#endif // NUMBEREDITOR_H
