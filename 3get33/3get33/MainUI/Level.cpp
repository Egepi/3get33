#include "Level.h"
#include <QGraphicsScene>

Level::Level(QGraphicsScene *theScene)
{
    myScene = theScene;
}

Level::~Level()
{
    delete this;
}

void Level::addWave()
{

}
