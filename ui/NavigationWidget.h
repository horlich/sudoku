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


class NavigationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationWidget(MainWidget* parent);

private:
    MainWidget* m_Parent;
    NewGameButton* m_BtNewGame;
};

#endif // NAVIGATIONWIDGET_H
