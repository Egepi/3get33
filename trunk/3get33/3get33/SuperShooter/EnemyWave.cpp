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
/*! Creates and adds QList of BasicShip objects to add to the scene.
  *
  * Author: Todd Silvia
  */
QList<BasicShip*>* EnemyWave::addWave()
{
    int tempX = 0;
    int tempY = 50;
    int lineCounter = 0;                //Loads which row the ship will be on
    for(int i=0; i < waveSize; i++)
    {
        //Allocates memory for new enemy
       enemy = new BasicShip(shipArmor,SHIP_LIVES,enemyImage,tempX, tempY, 1);
       //Inserts enemy into QList, also as part of the enemy wave
       //waveList.insert(i, enemy);
       waveList.append(enemy);
       //Add enemy to the scene
       myScene->addItem(enemy);
       //Increase the x location of the next BasicShip object
       tempX += 110;
       //Increase lineCounter
       lineCounter++;
       if(lineCounter >= ROW_SIZE)
       {//This starts a new row for this enemy ship
           lineCounter = 0;
           tempX = 0;
           tempY += 150;
       }
    }
    //Creates a pointer to the QList of enemy ships.
    QList<BasicShip*> *ptr = &(waveList);
    return ptr;
}

