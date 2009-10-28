#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "BasicShip.h"
#include "BossShip.h"

class Level
{
    public:
        Level(QGraphicsScene *theScene, QImage *enemyType, int theWaveSize);
        ~Level();
        void addWave();
        void startBoss();

    private:
        QImage *enemyImage;
        QGraphicsScene *myScene;
        int waveSize;
        BasicShip *enemy;
        QList<BasicShip*> waveList;
         QTimer *advanceTimer;
};


#endif // LEVEL_H
