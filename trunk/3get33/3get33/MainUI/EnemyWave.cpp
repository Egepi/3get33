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
    int tempX = 50;
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
           tempX = 50;
           tempY += 110;
       }
    }
}
