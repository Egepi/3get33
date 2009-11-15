#ifndef BOSSSHIP_H
#define BOSSSHIP_H

#include "BasicShip.h"
#include <QGraphicsItem>

class BossShip : public BasicShip
{
    public:
        BossShip();
        ~BossShip();
        enum { Type = 65536 + 3 };
        int type() const;
    private:
        void advance(int phase);
        bool moveLeft;
        
        

};


#endif // BOSSSHIP_H
