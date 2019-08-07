#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"
class HumanPlayer: public Player{

public:

    HumanPlayer(PlayerColor _color);

    ~HumanPlayer();

    void layStone(GameScene& scene, GameMap map, ClickedPoint clickedPoint);

private:

    PlayerColor color;

};
#endif // HUMANPLAYER_H
