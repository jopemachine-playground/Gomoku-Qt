//  ==============================+===============================================================
//  @ Author : jopemachine
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
