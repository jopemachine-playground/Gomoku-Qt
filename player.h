//  ==============================+===============================================================
//  @ Author : jopemachine
//  @ Created : 2019-08-07, 19:27:33
//  @ Desc : HumanPlayer와 ComputerPlayer를 자식으로 가짐.
//  ==============================+===============================================================

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
