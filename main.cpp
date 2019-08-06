#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    QPoint p = w.mapFromGlobal(QCursor::pos());

    qDebug() << p << endl;

    return app.exec();
}
