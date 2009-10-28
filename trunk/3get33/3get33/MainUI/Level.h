#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "BasicShip.h"

class Level
{
    public:
        Level(QGraphicsScene *theScene, QImage *enemyType, int theWaveSize);
        ~Level();
        void addWave();

    private:
        QImage *enemyImage;
        QGraphicsScene *myScene;
        int waveSize;
        BasicShip *enemy;


};


#endif // LEVEL_H
