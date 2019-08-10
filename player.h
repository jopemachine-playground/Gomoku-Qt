#ifndef PLAYER_H
#define PLAYER_H

#include "gamescene.h"

class Player{

public:

    Player(){}

    virtual ~Player();

    virtual void layStone(GameScene& scene, GameMap map, ClickedPoint clickedPoint) = 0;

    enum PlayerColor{
        black = -1,
        white = 1
    };

    inline PlayerColor getColor(){
        return color;
    }

protected:

    PlayerColor color;

};

typedef Player::PlayerColor PlayerColor;

#endif // PLAYER_H
