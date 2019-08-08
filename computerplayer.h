#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"
class ComputerPlayer: public Player{

public:

    ComputerPlayer(PlayerColor _color);

    ~ComputerPlayer();

    void layStone(GameScene& scene, GameMap map, ClickedPoint clickedPoint);


private:

    bool isCalculating;

    PlayerColor color;

};


#endif // COMPUTERPLAYER_H
