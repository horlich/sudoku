#include "MainWindow.h"
#include "ui/MainWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Sudoku");
    MainWidget* mw = new MainWidget(this);
    setCentralWidget(mw);
}

