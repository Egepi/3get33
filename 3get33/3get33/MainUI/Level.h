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
    Q_OBJECT
    public:
        Level(QGraphicsScene *theScene, QImage enemyType, int theWaveSize);
        ~Level();
        //void addWave();
        void startBoss();
        //void set
        BossShip *theBoss;
        static const int ROW_SIZE = 5;

    public slots:
        void addWave();

    private:
        QImage enemyImage;
        QGraphicsScene *myScene;
        int waveSize;
        BasicShip *enemy;
        QList<BasicShip*> waveList;
        QTimer *advanceTimer;
};


#endif // LEVEL_H
