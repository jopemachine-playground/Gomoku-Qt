#ifndef RESOURCE_H
#define RESOURCE_H

#define RESPATH_BOARDPLATE "resource/img/boardplate_594.png"
#define RESPATH_WHITESTONE "resource/img/white_32.png"
#define RESPATH_BLACKSTONE "resource/img/black_32.png"

#include <utility>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <vector>
#include <gamescene.h>

class ResourceManager{
public:

    static ResourceManager* getInstance();

    QGraphicsPixmapItem* getBoardPlate();

    void genWhiteStone(GameScene& scene, std::pair<int, int> pos){

        auto whiteStoneItem = new QGraphicsPixmapItem(*whiteStone);

        whiteStoneItem->setPos(pos.first, pos.second);

        itemVector->push_back(whiteStoneItem);

        scene.addItem(whiteStoneItem);
    }

    void genBlackStone(GameScene& scene, std::pair<int, int> pos){

        auto blackStoneItem = new QGraphicsPixmapItem(*blackStone);

        blackStoneItem->setPos(pos.first, pos.second);

        itemVector->push_back(blackStoneItem);

        scene.addItem(blackStoneItem);
    }

private:

    ResourceManager();

    ~ResourceManager();

    std::vector<QGraphicsPixmapItem*> *itemVector;

    QGraphicsPixmapItem* boardPlate;

    QPixmap* whiteStone;

    QPixmap* blackStone;

    static ResourceManager* instance;

};


#endif // RESOURCE_H
