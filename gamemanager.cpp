#include "constant.h"
#include "gamemanager.h"
#include <memory.h>

#include "player.h"
#include "humanplayer.h"
#include "computerplayer.h"

GameManager* GameManager::instance = nullptr;

GameManager* GameManager::getInstance(){
    if(instance == nullptr){
        instance = new GameManager();
    }
    return instance;
}

GameManager::~GameManager(){
    delete instance;
    delete client;
    delete opponent;
}

void GameManager::initGame(){

    // 게임을 새로 시작하는 경우 기존의 플레이어 객체들은 제거한다
    if(client != nullptr || opponent != nullptr){
        delete client;
        delete opponent;
    }

    turn = 0;

    gameMap = new nodeState* [BOARD_LENGTH_X];
    for (int i = 0; i < BOARD_LENGTH_X; i++){
        gameMap[i] = new nodeState[BOARD_LENGTH_Y];
        memset(gameMap[i], 0, sizeof(nodeState) * BOARD_LENGTH_Y);
    }

    modeSet();

    // 세트된 모드에 따라 플레이어 객체 생성
    switch (game.p_mode) {

        case gameMode::humanVshuman:

        if(game.p_order == gameOrder::playerFirst){
            client = new HumanPlayer(PlayerColor::black);
            opponent = new HumanPlayer(PlayerColor::white);
        }
        else {
            client = new HumanPlayer(PlayerColor::white);
            opponent = new HumanPlayer(PlayerColor::black);
        }

        break;

        case gameMode::humanVsCom:

        if(game.p_order == gameOrder::playerFirst){
            client = new HumanPlayer(PlayerColor::black);
            opponent = new ComputerPlayer(PlayerColor::white);
        }
        else {
            client = new HumanPlayer(PlayerColor::white);
            opponent = new ComputerPlayer(PlayerColor::black);
        }

        break;

        case gameMode::ComVsCom:

        if(game.p_order == gameOrder::playerFirst){
            client = new ComputerPlayer(PlayerColor::black);
            opponent = new ComputerPlayer(PlayerColor::white);
        }
        else {
            client = new ComputerPlayer(PlayerColor::white);
            opponent = new ComputerPlayer(PlayerColor::black);
        }

        break;
    }


}

bool GameManager::checkGameOver(std::pair<int, int> clickedPoint){


}

GameManager::GameManager(){
    initGame();
}
