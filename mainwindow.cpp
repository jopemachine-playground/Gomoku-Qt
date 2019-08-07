#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resourcemanager.h"
#include "constant.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameScene = new GameScene(this);
    gameScene->boardplateLoad();
    ui->graphicsView->setScene(gameScene);
    setWindowTitle(WIN_TITLE);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{
    auto res = ResourceManager::getInstance();
    auto gm = GameManager::getInstance();
    gm->initGame();
    res->deleteAllItem(*gameScene);
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionhuman_vs_human_triggered()
{
    auto gm = GameManager::getInstance();
    gm->setGameMode(GameManager::gameMode::humanVshuman);
}

void MainWindow::on_actionhuman_vs_com_triggered()
{
    auto gm = GameManager::getInstance();
    gm->setGameMode(GameManager::gameMode::humanVsCom);
}

void MainWindow::on_actioncom_vs_com_triggered()
{
    auto gm = GameManager::getInstance();
    gm->setGameMode(GameManager::gameMode::ComVsCom);
}

void MainWindow::on_actionPlayer_first_triggered()
{
    auto gm = GameManager::getInstance();
    gm->setGameOrder(GameManager::gameOrder::playerFirst);
}

void MainWindow::on_actionComputer_first_triggered()
{
    auto gm = GameManager::getInstance();
    gm->setGameOrder(GameManager::gameOrder::comFirst);
}
