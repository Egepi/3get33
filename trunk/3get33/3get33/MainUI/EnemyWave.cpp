#include "EnemyWave.h"

EnemyWave::EnemyWave(QGraphicsScene *theScene, QImage theEnemyType,
                     int theWaveSize, int theArmor)
{
    myScene = theScene;
    waveSize = theWaveSize;
    shipArmor = theArmor;
    enemyImage = theEnemyType;


}

EnemyWave::~EnemyWave()
{
}

void EnemyWave::addWave()
{
    int tempX = 0;
    int tempY = 50;
    int lineCounter = 0;
    for(int i=0; i < waveSize; i++)
    {
        //Allocates memory for new enemy
       enemy = new BasicShip(shipArmor,SHIP_LIVES,enemyImage,tempX, tempY);
       //Inserts enemy into QList, also as part of the enemy wave
       waveList.insert(i, enemy);
       //Add enemy to the scene
       myScene->addItem(enemy);
       tempX += 110;
       lineCounter++;
       if(lineCounter >= ROW_SIZE)
       {
           lineCounter = 0;
           tempX = 0;
           tempY += 110;
       }
    }

    if(waveSize >= ROW_SIZE)
    {
        waveRight = waveList.at(ROW_SIZE)->x() + SHIP_SIZE;
    }
    else
    {
        waveRight = waveList.last()->x() + SHIP_SIZE;
    }
}

void EnemyWave::moveWave()
{

    if((waveRight + 10) <= VIEW_SIZE)
    {
        for(int i=0; i < waveSize; i++)
        {
            waveList.at(i)->setPos(waveList.at(i)->x() + 10, 0);
        }
    }
}

