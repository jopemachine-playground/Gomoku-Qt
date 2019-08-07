#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "constant.h"
#include "gamescene.h"

GameScene::GameScene(QWidget *parent): QGraphicsScene(parent){}

bool GameScene::isValidInput(GameMap map, ClickedPoint clickedPoint){

    if(clickedPoint.first == - 1){
        return false;
    }

    return map[clickedPoint.first][clickedPoint.second]
            == nodeState::empty ? true : false;
}

void GameScene::layStone(ClickedPoint clickedPoint)
{

}

ClickedPoint GameScene::inputToMap(QPointF& pixelPoint)
{
    int x = static_cast<int>(pixelPoint.rx());
    int y = static_cast<int>(pixelPoint.ry());

    int relevantX = x - (x % ONE_RECT_LENGTH);
    int relevantY = y - (y % ONE_RECT_LENGTH);

    if((relevantX + ONE_RECT_LENGTH - x) % ONE_RECT_LENGTH < (x - relevantX) % ONE_RECT_LENGTH) relevantX += ONE_RECT_LENGTH;
    if((relevantY + ONE_RECT_LENGTH - y) % ONE_RECT_LENGTH < (y - relevantY) % ONE_RECT_LENGTH) relevantY += ONE_RECT_LENGTH;

    int indexX = relevantX / ONE_RECT_LENGTH;
    int indexY = relevantY / ONE_RECT_LENGTH;

    return {indexX, indexY};
}


void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    auto gm = GameManager::getInstance();
    auto map = gm->getMap();

    QPointF pixelPoint = event->scenePos();

    // 클릭 포인트 판정 및 처리
    std::pair<int, int> clickedPoint = inputToMap(pixelPoint);

    qDebug() << clickedPoint.first << " " << clickedPoint.second;

    if(!isValidInput(map, clickedPoint)){
        return;
    }

    // 돌을 둠
    layStone(clickedPoint);

    if(gm->checkGameOver({0,0})){
        // 게임 오버 조건 만족 및 이벤트 처리

    }



    qDebug() << pixelPoint.rx() << " " << pixelPoint.ry();
}
