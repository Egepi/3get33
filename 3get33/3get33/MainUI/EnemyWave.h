#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H
#include "BasicShip.h"
#include <QGraphicsScene>
#include <QList>
class EnemyWave
{
    public:
        EnemyWave(QGraphicsScene *theScene, QImage theEnemyType, int theWaveSize, int theArmor);
        ~EnemyWave();
        void addWave();
        //void

        static const int ROW_SIZE = 5;
        static const int SHIP_LIVES = 1;

   private:
        int shipArmor;
        int waveSize;
        BasicShip *enemy;
        QList<BasicShip*> waveList;
        QGraphicsScene *myScene;
        QImage enemyImage;

};
#endif // ENEMYWAVE_H
