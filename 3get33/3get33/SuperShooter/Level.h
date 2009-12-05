#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "BasicShip.h"
#include "BossShip.h"
#include "EnemyWave.h"

class Level
{
    public:
        Level(QGraphicsScene *theScene, QImage enemyType, int theWaveSize);
        ~Level();
        QList<BasicShip*>* addWave();
        QTimer *advanceTimer;
        BossShip *theBoss;
        void startBoss();
        void shipAdvance();
        static const int ROW_SIZE = 5;

    private:
        /*! Holds image to apply to all enemy ships*/
        QImage enemyImage;
        /*! Pointer to gameScene */
        QGraphicsScene *myScene;
        /*! Contains all enemy ships in a given wave*/
        QList<BasicShip*> waveList;
        /*! Holds size of an enemy wave*/
        int waveSize;
        /*! Pointer to an enemy ship */
        BasicShip *enemy;
};

#endif // LEVEL_H
