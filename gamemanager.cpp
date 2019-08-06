#include "gamemanager.h"
#include <memory.h>

#define BOARD_LENGTH_X 19
#define BOARD_LENGTH_Y 19

#define RANGE_DIVISION 25

GameManager* GameManager::instance = nullptr;

GameManager* GameManager::getInstance(){
    if(instance == nullptr){
        instance = new GameManager();
    }
    return instance;
}

void GameManager::initGame(){
    turn = 0;

    gameMap = new nodeState* [BOARD_LENGTH_X];
    for (int i = 0; i < BOARD_LENGTH_X; i++){
        gameMap[i] = new nodeState[BOARD_LENGTH_Y];
        memset(gameMap[i], 0, sizeof(nodeState) * BOARD_LENGTH_Y);
    }



}

bool GameManager::checkGameOver(std::pair<int, int> clickedPoint){


}

GameManager::GameManager(){
    initGame();
}
