#include "computerplayer.h"
#include "resourcemanager.h"
#include "constant.h"
#include "gamescene.h"

ComputerPlayer::~ComputerPlayer(){

}

ComputerPlayer::ComputerPlayer(PlayerColor _color){
    this->color = _color;
}

void ComputerPlayer::layStone(GameScene& scene, GameMap map, ClickedPoint clickedPoint){

    auto res = ResourceManager::getInstance();

    map[clickedPoint.first][clickedPoint.second] = static_cast<nodeState>(this->color);

    std::pair<int, int> genPt =
        {clickedPoint.first * ONE_RECT_LENGTH - 16, clickedPoint.second * ONE_RECT_LENGTH - 16};

    if(static_cast<nodeState>(color) == nodeState::white) res->genWhiteStone(scene, genPt);

    res->genBlackStone(scene, genPt);

}
