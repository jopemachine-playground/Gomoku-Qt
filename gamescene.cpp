#include <QDebug>
#include "gamescene.h"

GameScene::GameScene(QWidget *parent): QGraphicsScene(parent){

}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // QPoint p = event->screenPos();
    qDebug() << "p" << endl;
}
