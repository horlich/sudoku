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
//    static const QPalette& blackPalette();
//    static const QPalette& whitePalette();

    explicit NumberEditor(ItemStackedWidget *parent = nullptr);

signals:
    void finalNumberSelected(int);
    void trialNumberSelected(int);
};

#endif // NUMBEREDITOR_H
