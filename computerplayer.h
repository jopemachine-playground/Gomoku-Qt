//  ==============================+===============================================================
//  @ Author : jopemachine
//  @ Created : 2019-08-07, 19:30:06
//  ==============================+===============================================================

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"

class ComputerPlayer: public Player{

public:

    ComputerPlayer(PlayerColor _color);

    ~ComputerPlayer() override;

    void layStone(GameScene& scene, GameMap map, ClickedPoint clickedPoint) override;

private:

    bool isCalculating;

};


#endif // COMPUTERPLAYER_H
