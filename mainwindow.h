//  ==============================+===============================================================
//  @ Author : jopemachine
//  @ Created : 2019-08-05, 22:08:59
//  ==============================+===============================================================

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QActionGroup>
#include <QMainWindow>
#include <QLCDNumber>
#include "gamescene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    static MainWindow* getInstance();

    ~MainWindow();

    void setTurnNumber(const QString&);

private slots:

    void on_actionExit_triggered();

    void on_actionNew_Game_triggered();

    void on_actionhuman_vs_human_triggered();

    void on_actionhuman_vs_com_triggered();

    void on_actioncom_vs_com_triggered();

    void on_actionPlayer_first_triggered();

    void on_actionComputer_first_triggered();

    void timeUpdate();

private:

    int elapsedTime;

    static MainWindow* instance;

    explicit MainWindow(QWidget *parent = nullptr);

    Ui::MainWindow *ui;

    QMenu *menu;
    QActionGroup* modeGroup;
    QAction* menuAction;

    GameScene *gameScene;

    QTimer* timer;

    void setMenubar();

};

#endif // MAINWINDOW_H
