#include "NavigationWidget.h"
#include "MainWidget.h"
#include "QVBoxLayout"


NewGameButton::NewGameButton(NavigationWidget* parent)
    : QPushButton(parent)
{
    setText("Neues Spiel");
}


NavigationWidget::NavigationWidget(MainWidget* parent)
    : QWidget{parent}
    , m_Parent{parent}
    , m_BtNewGame{new NewGameButton{this}}
{
    QVBoxLayout* layout = new QVBoxLayout{this};
    layout->addWidget(m_BtNewGame, 0, Qt::AlignCenter);
    connect(m_BtNewGame, &QPushButton::clicked, parent, &MainWidget::displayStartBoard);
}
