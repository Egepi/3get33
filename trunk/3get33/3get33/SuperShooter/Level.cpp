/** File: Level.cpp
  * Header: Level.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: This class is used to handle the operation of a level in
  *          a SuperShooter game. It is responsible for creating the
  *          enemy ships, the boss ship, as well as moving the enemy
  *          ships.
  */

#include "Level.h"


/**********************************************************************/
/*! Basic constructor for a SuperShooter level.
 *
 * Author: Todd Silvia
 */
Level::Level(QGraphicsScene *theScene, QImage enemyType, int theWaveSize)
{
    myScene = theScene;
    waveSize = theWaveSize;
    enemyImage = enemyType;
}

/**********************************************************************/
/*! Basic de-structur for a SuperShooter level.
 *
 * Author: Todd Silvia
 */
Level::~Level()
{
}

/**********************************************************************/
/*! Creates a QList of enemy ships, creating an entire wave of enemy ships.
 *
 * The enemy ships are by default "BadGuy4.png" Which are the blue diamonds.
 *
 * Author: Todd Silvia
 */
QList<BasicShip*>* Level::addWave()
{
    QImage theEnemyPicture(":/images/BadGuy4.png");
    //Creates the enemy ship, with default properties of the pre-made level
    EnemyWave *theEnemyWave = new EnemyWave(myScene, enemyImage,10,100);
    return theEnemyWave->addWave();
}

/**********************************************************************/
/*! Creates the advance timer for the purpose of moving the ships on the scene.
 *
 * Author: Jennifer Kinahan
 */
void Level::shipAdvance()
{
    advanceTimer = new QTimer;
    //Connect the timer to the advance function of the enemy ships.
    QObject::connect(advanceTimer, SIGNAL(timeout()), myScene, SLOT(advance()));
    // Set the timer to trigger ever 1/3 of a second.
    advanceTimer->start(1000/33);
}

/**********************************************************************/
/*! Creates the boss ship, and adds it to the scene.
 *
 *  Author: Todd Silvia
 */
void Level::startBoss()
{
    theBoss = new BossShip();       //Create the boss ship
    myScene->addItem(theBoss);      //Add the boss ship to the scene
}
