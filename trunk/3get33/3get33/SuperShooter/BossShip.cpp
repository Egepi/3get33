/** File: BossShip.cpp
  * Header: BossShip.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: This class extends BasicShip, to make the boss ship for the
  *          SuperShooter level. Responsible for constructing and implementing
  *          the boss's movement.
  */
#include "BossShip.h"

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
BossShip::BossShip()
{
    this->setPos(250,10);
    this->setImage(QImage(":/images/boss.png"));
    moveLeft = true;
    this->shipSizeX = 150;
    this->shipSizeY = 63;
    this->setArmor(500);
    this->setZValue(10);
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
    if(this->isEnabled()==false) return;
    this->collCheck();
    if(((this->x() - 2) >=0)&&(moveLeft == true))
    {
        this->move(-2,0);
    }
    else
    {
        moveLeft = false;
    }
    if(((this->x() + 2) <=(600-this->shipSizeX))&&(moveLeft == false))
    {
        this->move(2,0);
    }
    else
    {
        moveLeft = true;
    }
}

 int BossShip::type() const
 {
    // Enable the use of qgraphicsitem_cast with this item.
    return Type;
 }

 /**********************************************************************/
