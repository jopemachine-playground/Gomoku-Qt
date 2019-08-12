//  ==============================+===============================================================
//  @ Author : jopemachine
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
