#ifndef STARTBOARD_H
#define STARTBOARD_H

#include <QObject>
#include <QWidget>

class GameBoard;

class StartBoard : public QWidget
{
    Q_OBJECT
public:
    explicit StartBoard(GameBoard *parent);

signals:

};

#endif // STARTBOARD_H
