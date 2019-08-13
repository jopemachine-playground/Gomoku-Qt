//  ==============================+===============================================================
//  @ Author : jopemachine
//  @ Created : 2019-08-07, 19:29:06
//  ==============================+===============================================================

#include "humanplayer.h"
#include "resourcemanager.h"
#include "constant.h"
#include "gamescene.h"

HumanPlayer::~HumanPlayer(){

}

HumanPlayer::HumanPlayer(PlayerColor _color): Player() {
    this->color = _color;
}

void HumanPlayer::layStone(GameScene& scene, GameMap map, ClickedPoint clickedPoint){

    auto res = ResourceManager::getInstance();

    map[clickedPoint.first][clickedPoint.second] = static_cast<nodeState> (this->color);

    std::pair<int, int> genPt =
        {clickedPoint.first * ONE_RECT_LENGTH - 16, clickedPoint.second * ONE_RECT_LENGTH - 16};

    if(static_cast<nodeState>(color) == nodeState::white) res->genWhiteStone(scene, genPt);

    else res->genBlackStone(scene, genPt);

}
