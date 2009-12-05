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
/*! Basic constructor for a BossShip object.
 *
 * Author: Todd Silvia
 */
BossShip::BossShip()
{
    //Sets default values for a BossShip
    this->setPos(250,10);
    this->setImage(QImage(":/images/boss.png"));
    moveLeft = true;
    this->shipSizeX = 150;
    this->shipSizeY = 63;
    this->setArmor(500);
    this->setZValue(10);
}

/**********************************************************************/
/*! Basic de-constructor for a BossShip object.
 *
 * Author: Todd Silvia
 */
BossShip::~BossShip()
{
}

/**********************************************************************/
/*! Handles the movement of the BossShip across the SuperShooter level.
 *
 * Determines if the BossShip should be moving right or left acrros the level.
 *
 * Author: Todd Silvia
 */
void BossShip::advance(int phase)
{
    if(!phase) return;
    //Returns if the BossShip is not enabled.
    if(this->isEnabled()==false) return;
    //Checks for collision detection.
    this->collCheck();
    if(((this->x() - 2) >=0)&&(moveLeft == true))
    {//Moves the ship left, because it hasn't hit the left edge.
        this->move(-2,0);
    }
    else
    {//Set moveLeft to false to make the ship move right on next call.
        moveLeft = false;
    }
    if(((this->x() + 2) <=(600-this->shipSizeX))&&(moveLeft == false))
    {//Moves the ship to the right, because it hasn't hit the right edge.
        this->move(2,0);
    }
    else
    {//Set moveLeft to true to make the ship move left on next call
        moveLeft = true;
    }
}

/**********************************************************************/
/*! Determines the type of QGraphicsItem the ship is for collison detection.
  *
  * Author: Karan Chakrapani
  */
 int BossShip::type() const
 {
    // Enable the use of qgraphicsitem_cast with this item.
    return Type;
 }
