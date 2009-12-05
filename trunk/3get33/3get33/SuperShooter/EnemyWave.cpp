/** File: EnemyWave.cpp
  * Header: EnemyWave.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: This class is used to create a entire wave of enemy ships.
  *          So that all of the enemy ships in a wave are contained in
  *          a single QList.
  */

#include "EnemyWave.h"

/**********************************************************************/
/*! Constructor for a EnemyWave object, with values passed in.
  *
  * Author: Todd Silvia
  */
EnemyWave::EnemyWave(QGraphicsScene *theScene, QImage theEnemyType,
                     int theWaveSize, int theArmor)
{
    myScene = theScene;
    waveSize = theWaveSize;
    shipArmor = theArmor;
    enemyImage = theEnemyType;
}

/**********************************************************************/
/*! Basic deconstructor for EnemyWave object.
  */
EnemyWave::~EnemyWave()
{
}

/**********************************************************************/
QList<BasicShip*>* EnemyWave::addWave()
{
    int tempX = 0;
    int tempY = 50;
    int lineCounter = 0;
    for(int i=0; i < waveSize; i++)
    {
        //Allocates memory for new enemy
       enemy = new BasicShip(shipArmor,SHIP_LIVES,enemyImage,tempX, tempY, 1);
       //Inserts enemy into QList, also as part of the enemy wave
       //waveList.insert(i, enemy);
       waveList.append(enemy);
       //Add enemy to the scene
       myScene->addItem(enemy);
       tempX += 110;
       lineCounter++;
       if(lineCounter >= ROW_SIZE)
       {
           lineCounter = 0;
           tempX = 0;
           tempY += 150;
       }
    }

    if(waveSize >= ROW_SIZE)
    {
        //waveRight = waveList.at(ROW_SIZE)->x() + SHIP_SIZE;
    }
    else
    {
        //waveRight = waveList.last()->x() + SHIP_SIZE;
    }
    QList<BasicShip*> *ptr = &(waveList);
    return ptr;
}

