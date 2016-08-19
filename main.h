#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <widget.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Widget *mainWidget;
};

#endif // MAINWINDOW_H
