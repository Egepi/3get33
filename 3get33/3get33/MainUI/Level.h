#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsScene>

class Level
{
    public:
        Level(QGraphicsScene *theScene);
        ~Level();
        void addWave();

    private:
        QImage *enemyImage;
        QGraphicsScene *myScene;

};


#endif // LEVEL_H
