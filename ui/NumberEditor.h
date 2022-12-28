#ifndef NUMBEREDITOR_H
#define NUMBEREDITOR_H

#include <QObject>
#include <QWidget>
#include <QFrame>

class ItemStackedWidget;

class NumberEditor : public QFrame
{
    Q_OBJECT
public:
    explicit NumberEditor(ItemStackedWidget *parent = nullptr);

signals:

};

#endif // NUMBEREDITOR_H
