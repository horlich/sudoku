#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class MainWidget;
class NavigationWidget;


class NewGameButton : public QPushButton {
    Q_OBJECT
public:
    explicit NewGameButton(NavigationWidget* parent);

};


class CheckNumbersButton : public QPushButton
{
public:
    CheckNumbersButton(NavigationWidget* parent);
};


class NavigationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationWidget(MainWidget* parent);

private:
    MainWidget* m_Parent;
    NewGameButton* m_BtNewGame;
    CheckNumbersButton* m_CheckNumbersButton = nullptr;
};

#endif // NAVIGATIONWIDGET_H
