//  ==============================+===============================================================
//  @ Author : jopemachine
//  @ Created : 2019-08-05, 22:08:59
//  ==============================+===============================================================

#include "mainwindow.h"
#include "gamemanager.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *window = MainWindow::getInstance();
    window->show();
    return app.exec();
}
