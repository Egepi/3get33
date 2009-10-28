#ifndef BOSSSHIP_H
#define BOSSSHIP_H

#include "BasicShip.h"
#include "Bullet.h"
#include <QGraphicsItem>
#include <QImage>

class BossShip : public BasicShip
{
    public:
        BossShip();
        ~BossShip();
        void BossShip::advance(int phase);
        bool moveLeft;

    public slots:
        void bossShoot();
};


#endif // BOSSSHIP_H
