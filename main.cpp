#include "mainwindow.h"

#include <QApplication>
#include <iostream>
//#include <QWindowsXPStyle>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setStyle ( "fusion" ); // windowsvista , fusion ,  windows

    MainWindow w;
    w.show();
    return a.exec();
}
