#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H
#include "BasicShip.h"
#include <QGraphicsScene>
#include <QList>
#include <QObject>
class EnemyWave
{
    public:
        EnemyWave(QGraphicsScene *theScene, QImage theEnemyType, int theWaveSize, int theArmor);
        ~EnemyWave();
        QList<BasicShip*>* addWave();
        static const int ROW_SIZE = 5;
        static const int SHIP_LIVES = 1;
        static const int VIEW_SIZE = 600;
        static const int SHIP_SPACING = 30;

   private:
        /*! The amount of armor for the enemy ship*/
        int shipArmor;
        /*! Number of enemy ships in 1 wave*/
        int waveSize;
        /*! Holds the BasicShip object to be added to enemy wave*/
        BasicShip *enemy;
        /*! List to hold all of the enemy ships in a given wave*/
        QList<BasicShip*> waveList;
        /*! Pointer to gameScene*/
        QGraphicsScene *myScene;
        /*! Holds image to be used to display the enemy ships*/
        QImage enemyImage;

};
#endif // ENEMYWAVE_H
