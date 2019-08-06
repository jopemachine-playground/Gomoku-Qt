#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamescene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_Game_triggered();
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    GameScene *gameScene;

};

#endif // MAINWINDOW_H
