#ifndef GAMESCENE_H
#define GAMESCENE_H

#pragma once

#endif // GAMESCENE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class GameScene: public QGraphicsScene{

    Q_OBJECT

public:
    explicit GameScene(QWidget*);

    void mousePressEvent(QGraphicsSceneMouseEvent*);

private:

};
