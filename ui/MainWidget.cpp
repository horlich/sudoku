#include "MainWidget.h"
#include "MatrixWidget.h"
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new MatrixWidget(MatrixWidget::very_easy, this));
}
