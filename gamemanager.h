#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <utility>

typedef int TurnNumber;

class GameManager{
public:

    static GameManager* getInstance();

    TurnNumber turn;

    enum nodeState
        { black = -1, empty = 0, white = 1 };

    inline nodeState** getMap() const{
        return gameMap;
    }

    bool checkGameOver(std::pair<int, int> clickedPoint);

    void initGame();

    enum gameMode
        { humanVshuman, humanVsCom, ComVsCom };

    enum gameOrder
        { playerFirst, comFirst };

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

private:

    static GameManager* instance;

    typedef struct{
        gameMode p_mode;
        gameOrder p_order;
    } presentGame;

    presentGame game;

    gameMode mode;

    gameOrder order;

    nodeState** gameMap;

    GameManager();

    ~GameManager();
};

#endif // GAMEMANAGER_H
