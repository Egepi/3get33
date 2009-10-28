#include "Level.h"
#include "BasicShip.h"
#include <QGraphicsScene>

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
Level::Level(QGraphicsScene *theScene, QImage *enemyType, int theWaveSize)
{
    myScene = theScene;
    waveSize = theWaveSize;
}

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
Level::~Level()
{
    //
}

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
void Level::addWave()
{
    QList<BasicShip*> waveList;
    int tempX = 50;
    int tempY = 50;
    int lineCounter = 0;
    for(int i=0; i < waveSize; i++)
    {
        //Allocates memory for new enemy
        enemy = new BasicShip(100,1,QImage(":images/BadGuy4.png"), tempX, tempY);
        //Inserts enemy into QList, also as part of the enemy wave
        waveList.insert(i,enemy);
        //Add enemy to the scene
        myScene->addItem(enemy);
        tempX = tempX + 110;
        lineCounter++;
        //Checks if there are enough enemys in current row.
        if(lineCounter > 3)
        {//Creates new row for to fit more enimies
            lineCounter = 0;
            tempX = 50;
            tempY = tempY + 110;
        }
    }
    // Create a timer that sends a signal to the "advance()" slot of any
    // characters that are created.
    QTimer *timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), myScene, SLOT(advance()));
    // Set the timer to trigger ever 1/3 of a second.
    timer->start(1000/33);




}

/**********************************************************************/
/*!
 *
 *  Author: Todd Silvia
 */
void Level::startBoss()
{
    BasicShip *boss = new BasicShip(100,1,QImage(":/images/BadGuy1.png"),0,0);
    myScene->addItem(boss);
}
