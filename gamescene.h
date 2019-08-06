#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

#include "gamemanager.h"


class GameScene: public QGraphicsScene{

public:
    explicit GameScene(QWidget*);

    void mousePressEvent(QGraphicsSceneMouseEvent*);


private:

    void update(GameManager::nodeState** map);

};

#endif // GAMESCENE_H
