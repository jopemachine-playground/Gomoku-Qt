#include "resourcemanager.h"
#include "constant.h"

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
    items = new std::vector<QGraphicsPixmapItem*>;
}

ResourceManager::~ResourceManager(){
    delete instance;
    delete boardPlate;
    delete whiteStone;
    delete blackStone;
    delete items;
}

QGraphicsPixmapItem* ResourceManager::getBoardPlate(){
    return boardPlate;
}

void ResourceManager::genWhiteStone(GameScene& scene, std::pair<int, int> pos){

    auto whiteStoneItem = new QGraphicsPixmapItem(*whiteStone);

    whiteStoneItem->setPos(pos.first + START_PT, pos.second + START_PT);

    items->push_back(whiteStoneItem);

    scene.addItem(whiteStoneItem);
}

void ResourceManager::genBlackStone(GameScene& scene, std::pair<int, int> pos){

    auto blackStoneItem = new QGraphicsPixmapItem(*blackStone);

    blackStoneItem->setPos(pos.first + START_PT, pos.second + START_PT);

    items->push_back(blackStoneItem);

    scene.addItem(blackStoneItem);
}

void ResourceManager::deleteAllItem(GameScene& scene){

    for(auto i : *items){
        scene.removeItem(i);
        items->pop_back();
    }

}
