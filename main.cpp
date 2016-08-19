#include <QMainWindow>
#include <QApplication>
#include <main.h>



int main(int argc, char *argv[])
{
    QString a3;
    QApplication a(argc, argv);
    a.addLibraryPath(a.applicationDirPath()+"/plugins");


    MainWindow w;
    w.setGeometry(50,50,800,600);
    w.setFixedSize(800,600);
    w.show();


    return a.exec();
}


