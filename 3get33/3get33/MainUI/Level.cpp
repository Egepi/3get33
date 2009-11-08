#include "Level.h"
#include "BasicShip.h"
#include <QGraphicsScene>

/**********************************************************************/
/*!
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
/*!
 *
 * Author: Todd Silvia
 */
Level::~Level()
{
}

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
void Level::addWave()
{
    QImage theEnemyPicture(":/images/BadGuy4.png");
    EnemyWave *theEnemyWave = new EnemyWave(myScene, enemyImage,10,50);
    theEnemyWave->addWave();

    advanceTimer = new QTimer;
    QObject::connect(advanceTimer, SIGNAL(timeout()), myScene, SLOT(advance()));
    //QObject::connect(advanceTimer, SIGNAL(timeout()), theEnemyWave, SLOT(moveWave()));
    //QObject::connect(advanceTimer, SIGNAL(timeout()), theBoss, SLOT(
    // Set the timer to trigger ever 1/3 of a second.
    advanceTimer->start(1000/33);
}

/**********************************************************************/
/*!
 *
 *  Author: Todd Silvia
 */
void Level::startBoss()
{
    theBoss = new BossShip();
    myScene->addItem(theBoss);
}
