#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "constant.h"
#include "gamescene.h"
#include "resourcemanager.h"
#include "humanplayer.h"
#include "computerplayer.h"

#include <typeinfo>

GameScene::GameScene(QWidget *parent): QGraphicsScene(parent){}

bool GameScene::isValidInput(GameMap map, ClickedPoint clickedPoint){

    if(clickedPoint.first >= BOARD_SIZE || clickedPoint.second >= BOARD_SIZE ){
        return false;
    }

    return map[clickedPoint.first][clickedPoint.second]
            == nodeState::empty ? true : false;
}


ClickedPoint GameScene::inputToMap(QPointF& pixelPoint)
{
    int x = static_cast<int>(pixelPoint.rx());
    int y = static_cast<int>(pixelPoint.ry());

    // relevant 값은 클릭한 값보다 더 적은 ONE_RECT_LENGTH의 (가능한 가장 큰 값인) 배수
    int relevantX = x - (x % ONE_RECT_LENGTH);
    int relevantY = y - (y % ONE_RECT_LENGTH);

    // relevantX, relevantY가 이전의 Rect 칸 보다 이후의 Rect 칸에 가까운 경우, 좌표를 업데이트 한다
    if((relevantX + ONE_RECT_LENGTH - x) % ONE_RECT_LENGTH < (x - relevantX) % ONE_RECT_LENGTH)
        relevantX += ONE_RECT_LENGTH;
    if((relevantY + ONE_RECT_LENGTH - y) % ONE_RECT_LENGTH < (y - relevantY) % ONE_RECT_LENGTH)
        relevantY += ONE_RECT_LENGTH;

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

    // qDebug() << clickedPoint.first << " " << clickedPoint.second;

    if(!isValidInput(map, clickedPoint)){
        return;
    }

    // 돌을 둠
    auto player = gm->getPlayerByTurn();

    player->layStone(*this, map, clickedPoint);

    if(gm->checkGameOver(clickedPoint)){
        // 게임 오버 조건 만족 및 이벤트 처리
    }

    gm->nextTurn();

    // qDebug() << pixelPoint.rx() << " " << pixelPoint.ry();
}

void GameScene::boardplateLoad(){
    auto res = ResourceManager::getInstance();
    this->addItem(res->getBoardPlate());
}


