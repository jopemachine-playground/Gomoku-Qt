//  ==============================+===============================================================
//  @ Author : jopemachine
//  @ Created : 2019-08-07, 19:05:36
//  ==============================+===============================================================

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"

class HumanPlayer: public Player{

public:

    HumanPlayer(PlayerColor _color);

    ~HumanPlayer() override;

    void layStone(GameScene& scene, GameMap map, ClickedPoint clickedPoint) override;

};
#endif // HUMANPLAYER_H
