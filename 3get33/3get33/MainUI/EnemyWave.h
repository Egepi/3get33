#ifndef ENEMYWAVE_H
#define ENEMYWAVE_H
#include "BasicShip.h"
#include <QGraphicsScene>
#include <QList>
class EnemyWave : QObject
{
    Q_OBJECT
    public:
        EnemyWave(QGraphicsScene *theScene, QImage theEnemyType, int theWaveSize, int theArmor);
        ~EnemyWave();
        void addWave();
        static const int ROW_SIZE = 5;
        static const int SHIP_LIVES = 1;
        static const int VIEW_SIZE = 600;
        static const int SHIP_SPACING = 30;
   public slots:
        void moveWave();

   private:
        int shipArmor;
        int waveSize;
        int waveRight;
        bool moveRight;
        BasicShip *enemy;
        QList<BasicShip*> waveList;
        QGraphicsScene *myScene;
        QImage enemyImage;

};
#endif // ENEMYWAVE_H
