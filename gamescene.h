#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <utility>

#include "gamemanager.h"

typedef GameManager::nodeState** GameMap;

typedef GameManager::nodeState nodeState;

typedef std::pair<int, int> ClickedPoint;

class GameScene: public QGraphicsScene{

public:
    explicit GameScene(QWidget*);

    void mousePressEvent(QGraphicsSceneMouseEvent*);

    void boardplateLoad();

private:

    ClickedPoint inputToMap(QPointF& pixelPoint);

    bool isValidInput(GameMap map, ClickedPoint clickedPoint);

};

#endif // GAMESCENE_H
