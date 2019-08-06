#include "mainwindow.h"
#include "gamemanager.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    GameManager *gm = GameManager::getInstance();

    return app.exec();
}
