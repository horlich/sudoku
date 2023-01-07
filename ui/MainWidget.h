#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class NavigationWidget;
class GameBoard;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

    void displayStartBoard();

signals:

private:
    NavigationWidget* m_NavigationWidget;
    GameBoard* m_GameBoard;
};

#endif // MAINWIDGET_H
