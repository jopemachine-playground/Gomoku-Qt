//  ==============================+===============================================================
//  @ Author : jopemachine
//  ==============================+===============================================================

#include <memory.h>
#include <queue>
#include <utility>

#include "constant.h"
#include "gamemanager.h"
#include "player.h"
#include "humanplayer.h"
#include "computerplayer.h"
#include "mainwindow.h"

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

void GameManager::RestartGame(){

    MainWindow::getInstance()->setTurnNumber("0");

    // 게임을 새로 시작하는 경우 기존의 플레이어 객체들은 제거한다
    if(client != nullptr || opponent != nullptr){
        delete client;
        delete opponent;
    }

    InitGame();
}


void GameManager::InitGame(){

    turn = 0;

    game.isOver = false;

    gameMap = new nodeState* [BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++){
        gameMap[i] = new nodeState[BOARD_SIZE];
        memset(gameMap[i], 0, sizeof(nodeState) * BOARD_SIZE);
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

GameManager::winnerInfo GameManager::checkGameOver(std::pair<int, int> clickedPoint){

    // qDebug() << "cp: " << clickedPoint.first << " " << clickedPoint.second;

    // 클릭된 지점의 놓인 돌 색깔을 가져와 판단
    nodeState colorToJudge = gameMap[clickedPoint.first][clickedPoint.second];

    // qDebug() << "color: " << colorToJudge;

    int row = clickedPoint.first;
    int col = clickedPoint.second;

    int dir_right = 1, dir_left = 1, dir_top = 1, dir_down = 1, dir_2 = 1, dir_4 = 1, dir_7 = 1, dir_11 = 1;

    // 오른쪽 방향으로 확인
    if ((row + 1 < BOARD_SIZE && row >= 0) && gameMap[row + 1][col] == colorToJudge) {
        int i = row + 1;
        while(gameMap[i++][col] == colorToJudge){
            dir_right++;
        };
    }

    // 왼쪽 방향으로 확인
    if (row - 1 >= 0 && gameMap[row - 1][col] == colorToJudge) {
        int i = row - 1;
        while(gameMap[i--][col] == colorToJudge){
            dir_left++;
        };
    }

    // 아래 방향으로 확인
    if ((col + 1 < BOARD_SIZE && col >= 0) && gameMap[row][col + 1] == colorToJudge) {
        int i = col + 1;
        while(gameMap[row][i++] == colorToJudge){
            dir_down++;
        };
    }

    // 위쪽 방향으로 확인
    if (col - 1 >= 0 && gameMap[row][col - 1] == colorToJudge) {
        int i = col - 1 ;
        while(gameMap[row][i--] == colorToJudge){
            dir_top++;
        };
    }

    // 2시 방향으로 확인 (위쪽 방향이면서 오른쪽 방향)
    if(col - 1 >= 0 && (row + 1 < BOARD_SIZE && row >= 0) && gameMap[row + 1][col - 1] == colorToJudge){
        int c = col - 1, r = row + 1;
        while(gameMap[r++][c--] == colorToJudge){
            dir_2++;
        };
    }

    // 4시 방향으로 확인 (아래쪽 방향이면서 오른쪽 방향)
    if((col + 1 < BOARD_SIZE && col >= 0) && (row + 1 < BOARD_SIZE && row >= 0) && gameMap[row + 1][col + 1] == colorToJudge){
        int c = col + 1, r = row + 1;
        while(gameMap[r++][c++] == colorToJudge){
            dir_4++;
        };
    }

    // 7시 방향으로 확인 (아래쪽 방향이면서 왼쪽 방향)
    if((col + 1 < BOARD_SIZE && col >= 0) && row - 1 >= 0 && gameMap[row - 1][col + 1] == colorToJudge){
        int c = col + 1, r = row - 1;
        while(gameMap[r--][c++] == colorToJudge){
            dir_7++;
        };
    }

    // 11시 방향으로 확인 (위쪽 방향이면서 왼쪽 방향)
    if(col - 1 >= 0 && row - 1 >= 0 && gameMap[row - 1][col - 1] == colorToJudge){
        int c = col - 1, r = row - 1;
        while(gameMap[r--][c--] == colorToJudge){
            dir_11++;
        };
    }

    //        qDebug() << "#############";
    //        qDebug() << dir_right;
    //        qDebug() << dir_left;
    //        qDebug() << dir_top;
    //        qDebug() << dir_down;
    //        qDebug() << dir_2;
    //        qDebug() << dir_4;
    //        qDebug() << dir_7;
    //        qDebug() << dir_11;
    //        qDebug() << "#############";

    // 승리 조건을 만족한 경우
    if(dir_right + dir_left - 1 == 5 ||
       dir_top + dir_down - 1 == 5 ||
       dir_2 + dir_7 - 1 == 5 ||
       dir_4 + dir_11 -1 == 5)
    {
        return { getPlayerByTurn(), true };
    }

    return { nullptr, false };
}

GameManager::GameManager(){
    // 기본값 설정
    mode = gameMode::humanVshuman;
    order = gameOrder::playerFirst;

    InitGame();
}

Player* GameManager::getPlayerByTurn() const{
    if(game.p_order == gameOrder::playerFirst){
        return (turn % 2 == 0) ? client : opponent;
    }
    else {
        return (turn % 2 == 0) ? opponent : client;
    }
}


void GameManager::nextTurn(){
    ++turn;
    MainWindow::getInstance()->setTurnNumber(QString::number(turn));
}
