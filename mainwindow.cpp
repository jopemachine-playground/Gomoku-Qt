#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameScene = new GameScene(this);
    QGraphicsPixmapItem *map = new QGraphicsPixmapItem(QPixmap("resource/img/goardEdited_594.png"));
    gameScene->addItem(map);
    ui->graphicsView->setScene(gameScene);
    setWindowTitle("Omok");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}
