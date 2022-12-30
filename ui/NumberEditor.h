#ifndef NUMBEREDITOR_H
#define NUMBEREDITOR_H

#include <QObject>
#include <QWidget>
#include <QFrame>

class ItemStackedWidget;

class NumberEditor : public QFrame
{
    //    static const QPalette& blackPalette();
    //    static const QPalette& whitePalette();
    Q_OBJECT

public:

    explicit NumberEditor(ItemStackedWidget *parent = nullptr);

signals:
    void finalNumberSelected(int);
    void trialNumberSelected(int);
};

#endif // NUMBEREDITOR_H
