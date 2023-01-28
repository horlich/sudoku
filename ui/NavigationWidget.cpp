#include "NavigationWidget.h"
#include "MainWidget.h"
#include "QVBoxLayout"


NewGameButton::NewGameButton(NavigationWidget* parent)
    : QPushButton(parent)
{
    setText("Neues Spiel");
}


CheckNumbersButton::CheckNumbersButton(NavigationWidget* parent)
    : QPushButton(parent)
{
    setText("Prüfen");
}


NavigationWidget::NavigationWidget(MainWidget* parent)
    : QWidget{parent}
    , m_Parent{parent}
    , m_BtNewGame{new NewGameButton{this}}
    , m_CheckNumbersButton{new CheckNumbersButton{this}}
{
    QVBoxLayout* layout = new QVBoxLayout{this};
    layout->addWidget(m_BtNewGame, 0, Qt::AlignCenter);
    layout->addWidget(m_CheckNumbersButton, 0, Qt::AlignCenter);
    connect(m_BtNewGame, &QPushButton::clicked, parent, &MainWidget::displayStartBoard);
    connect(m_CheckNumbersButton, &QPushButton::clicked, parent, &MainWidget::checkNumbers);
}
