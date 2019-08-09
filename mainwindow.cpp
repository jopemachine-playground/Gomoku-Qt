#include <QActionGroup>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resourcemanager.h"
#include "constant.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    GameManager::Init(this);
    GameManager::getInstance();
    setFixedSize(WIN_SIZE_X, WIN_SIZE_Y);
    ui->setupUi(this);
    gameScene = new GameScene(this);
    gameScene->boardplateLoad();
    ui->graphicsView->setScene(gameScene);

    turnLCD = ui->turnLCD;
    elapsedTimeLCD = ui->elapsedTimeLCD;

    setWindowTitle(WIN_TITLE);
    setMenubar();
}

void MainWindow::setMenubar(){

    auto res = ResourceManager::getInstance();

    // Mode Setting 메뉴 추가
    menu = menuBar()->addMenu("Setting");
    auto modeSettingMenu = menu->addMenu("Mode Setting");

    // modeGroup 그룹 추가
    modeGroup = new QActionGroup(modeSettingMenu);
    modeGroup->setExclusive(true);

    // Human vs Human 버튼 추가
    menuAction = modeSettingMenu->addAction("Human vs Human");
    menuAction->setCheckable(true);
    menuAction->setChecked(true);
    modeGroup->addAction(menuAction);
    connect(menuAction, SIGNAL(triggered()), this, (SLOT(on_actionhuman_vs_human_triggered())));

    // Human vs Com 버튼 추가
    menuAction = modeSettingMenu->addAction("Human vs Computer");
    menuAction->setCheckable(true);
    modeGroup->addAction(menuAction);
    connect(menuAction, SIGNAL(triggered()), this, (SLOT(on_actionhuman_vs_com_triggered())));

    // Com vs Com 버튼 추가
    menuAction = modeSettingMenu->addAction("Computer vs Computer");
    menuAction->setCheckable(true);
    modeGroup->addAction(menuAction);
    connect(menuAction, SIGNAL(triggered()), this, (SLOT(on_actioncom_vs_com_triggered())));

    // Mode Setting 메뉴 추가
    auto orderSettingMenu = menu->addMenu("Game Order");

    // modeGroup 그룹 추가
    modeGroup = new QActionGroup(orderSettingMenu);
    modeGroup->setExclusive(true);

    // Player First 버튼 추가
    QIcon bsIcon = QIcon(*(res->getBlackStonePixMap()));
    menuAction = orderSettingMenu->addAction(bsIcon, "Player First");
    menuAction->setCheckable(true);
    menuAction->setChecked(true);
    modeGroup->addAction(menuAction);
    connect(menuAction, SIGNAL(triggered()), this, (SLOT(on_actionPlayer_first_triggered())));

    // Computer First 버튼 추가
    QIcon wsIcon = QIcon(*(res->getWhiteStonePixMap()));
    menuAction = orderSettingMenu->addAction(wsIcon, "Computer First");
    menuAction->setCheckable(true);
    modeGroup->addAction(menuAction);
    connect(menuAction, SIGNAL(triggered()), this, (SLOT(on_actionPlayer_first_triggered())));

}


MainWindow::~MainWindow()
{
    delete ui;
    delete modeGroup;
}

void MainWindow::setTurnNumber(const QString& number){
    turnLCD->display(number);
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
