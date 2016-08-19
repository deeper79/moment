#include "main.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    mainWidget = new Widget(this);

}

MainWindow::~MainWindow()
{

}
