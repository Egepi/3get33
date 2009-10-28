#include "BossShip.h"

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
BossShip::BossShip()
{
    this->setPos(250,10);
    this->setImage(QImage(":/images/BadGuy1.png"));
}

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
BossShip::~BossShip()
{
}

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
void BossShip::advance(int phase)
{
    if(!phase) return;
    this->move(-3,0);
}

