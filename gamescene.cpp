#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "gamescene.h"


GameScene::GameScene(QWidget *parent): QGraphicsScene(parent){

}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    auto gm = GameManager::getInstance();

    QPointF clickedPoint = event->scenePos();


    if(gm->checkGameOver({0,0})){
        // 게임 오버 조건 만족 및 이벤트 처리

    }



    qDebug() << clickedPoint.rx() << " " << clickedPoint.ry() << endl;
}
