#include "resourcemanager.h"

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager* ResourceManager::getInstance(){
    if(instance == nullptr){
        instance = new ResourceManager();
    }
    return instance;
}

ResourceManager::ResourceManager(){
    boardPlate = new QGraphicsPixmapItem(QPixmap(RESPATH_BOARDPLATE));
    whiteStone = new QPixmap(RESPATH_WHITESTONE);
    blackStone = new QPixmap(RESPATH_BLACKSTONE);
    itemVector = new std::vector<QGraphicsPixmapItem*>;
}

ResourceManager::~ResourceManager(){
    delete instance;
    delete boardPlate;
    delete whiteStone;
    delete blackStone;
    delete itemVector;
}

QGraphicsPixmapItem* ResourceManager::getBoardPlate(){
    return boardPlate;
}
