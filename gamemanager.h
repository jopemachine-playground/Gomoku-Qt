#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <utility>

class GameManager{
public:
    static GameManager* instance;

    static GameManager* getInstance();

    int turn;

    enum nodeState
        { black = -1, empty = 0, white = 1 };

    inline nodeState** getMap() const{
        return gameMap;
    }

    bool checkGameOver(std::pair<int, int> clickedPoint);

private:

    nodeState** gameMap;

    void initGame();

    GameManager();

};

#endif // GAMEMANAGER_H
