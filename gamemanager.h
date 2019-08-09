#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <utility>
#include <QLCDNumber>

class Player;

typedef int TurnNumber;

class GameManager{
public:

    enum gameMode
        { humanVshuman, humanVsCom, ComVsCom };

    enum gameOrder
        { playerFirst, comFirst };

    enum nodeState
        { black = -1, empty = 0, white = 1 };

    typedef struct{
        gameMode p_mode;
        gameOrder p_order;
        bool isOver;
    } presentGame;

    typedef struct{
        Player* winner;
        bool isOver;
    } winnerInfo;

    static GameManager* getInstance();

    inline nodeState** getMap() const{
        return gameMap;
    }

    winnerInfo checkGameOver(std::pair<int, int> clickedPoint);

    void RestartGame();

    inline void setGameMode(const gameMode _mode){
        mode = _mode;
    }

    inline void setGameOrder(const gameOrder _order){
        order = _order;
    }

    inline void modeSet(){
        game.p_mode = mode;
        game.p_order = order;
    }

    inline TurnNumber getTurn(){
        return turn;
    }

    void nextTurn();

    inline void gameOver(){
        game.isOver = true;
    }

    inline bool isGameOver(){
        return game.isOver;
    }

    Player* getPlayerByTurn() const;

private:

    Player* client;

    Player* opponent;

    static GameManager* instance;

    presentGame game;

    gameMode mode;

    gameOrder order;

    nodeState** gameMap;

    TurnNumber turn;

    void InitGame();

    GameManager();

    ~GameManager();
};


#endif // GAMEMANAGER_H
