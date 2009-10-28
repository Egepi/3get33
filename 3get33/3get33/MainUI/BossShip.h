#ifndef BOSSSHIP_H
#define BOSSSHIP_H

#include "BasicShip.h"
#include <QGraphicsItem>
#include <QImage>

class BossShip : public BasicShip
{
    public:
        BossShip();
        ~BossShip();
        void BossShip::advance(int phase);
        bool moveLeft;
};


#endif // BOSSSHIP_H
