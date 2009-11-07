#include "playership.h"
#include "BasicShip.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QPainter>
#include <QPushButton>

/**********************************************************************/
/*! Constructor for PlayerShip. Sets default characteristics.
 *
 *
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
PlayerShip::PlayerShip()
{
    lFlag = false;
    rFlag = false;
    dFlag = false;
    uFlag = false;
    this->setPos(260,400);
    this->setArmor(10);
    this->setShield(10);
    this->setLives(0);
    this->setImage(QImage(":/images/GoodGuy.png"));
    this->setGraphicType(2);
    this->shipSize = 80;
}

/**********************************************************************/
/*! Destructor for PlayerShip
 *
 *  Author: Todd Silvia
 */
PlayerShip::~PlayerShip()
{
    delete this;
}

/**********************************************************************/
/*! Sets flag to true if user is pressing 'a' and false if 'a' is released.
 *
 *  Author: Jennifer Kinahan
 */
void PlayerShip::setLFlag( bool keyPress )
{
    lFlag = keyPress;
}

/**********************************************************************/
/*! Sets flag to true if user is pressing 'd' and false if 'd' is released.
 *
 *  Author: Jennifer Kinahan
 */
void PlayerShip::setRFlag( bool keyPress )
{
    rFlag = keyPress;
}

/**********************************************************************/
/*! Sets flag to true if user is pressing 's' and false if 's' is released.
 *
 *  Author: Jennifer Kinahan
 */
void PlayerShip::setDFlag( bool keyPress )
{
    dFlag = keyPress;
}

/**********************************************************************/
/*! Sets flag to true if user is pressing 'w' and false if 'w' is released.
 *
 *  Author: Jennifer Kinahan
 */
void PlayerShip::setUFlag( bool keyPress )
{
    uFlag = keyPress;
}

/**********************************************************************/
/*! Decides which direction to move the ship based on the 4 directinoal flags.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advance(int phase)
{
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

    if (!listOfCollidingItems.isEmpty())
    {
        int length = listOfCollidingItems.length();

        for (int i = 0; i < length; i++)
        {
            QGraphicsItem *item = listOfCollidingItems.at(i);
            //if a basic enemy ship
            if (item->type() == 65537)
            {
                //this->setArmor(this->getArmor()-10);
            }
            //if a player ship
            if (item->type() == 65538)
            {
                //this->setArmor(this->getArmor()-10);
            }
            //if a boss ship
            if (item->type() == 65539)
            {
                //this->setArmor(this->getArmor()-30);
            }
            //if a bullet
            if (item->type() == 65540)
            {
                if (this->getShield() > 0)
                {
                    this->setShield(this->getShield()-10);
                }
                else if (this->getArmor() > 0)
                {
                    this->setArmor(this->getArmor()-10);
                }
                else if (this->getLives() > 0)
                {
                    this->setLives(this->getLives()-1);
                    this->setShield(100);
                    this->setArmor(100);
                }
                else
                {
                   this->setImage(QImage(":/images/explosion.png"));
                }
                item->setPos(500,500);
            }
        }

    }

    if(!phase) return;
    //left movement
    if(( lFlag ) && ( !dFlag ) && ( !rFlag ) && ( !uFlag )){
        advanceLeft();
    }
    //right movement
    else if(( !lFlag ) && ( !dFlag ) && ( rFlag ) && ( !uFlag )){
        advanceRight();
    }
    //down movement
    else if(( !lFlag ) && ( dFlag ) && ( !rFlag ) && ( !uFlag )){
        advanceDown();
    }
    else if(( !lFlag ) && ( !dFlag ) && ( !rFlag ) && ( uFlag )){
        advanceUp();
    }
    //up movement
    else if(( lFlag ) && ( dFlag ) && ( !rFlag ) && ( !uFlag )){
        advanceLeftDown();
    }
    //left-up movement
    else if(( lFlag ) && ( uFlag ) && ( !rFlag ) && ( !dFlag )){
        advanceLeftUp();
    }
    //right-down movement
    else if(( rFlag ) && ( dFlag ) && ( !lFlag ) && ( !uFlag )){
        advanceRightDown();
    }
    //right-up movement
    else if(( rFlag ) && ( uFlag ) && ( !lFlag ) && ( !dFlag )){
        advanceRightUp();
    }
}

/**********************************************************************/
/*! Moves the PlayerShip Left 5 pixels.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advanceLeft()
{
    this->move(-5,0);
}

/**********************************************************************/
/*! Moves the Player Ship Left and Down diagonally equal to 5 pixels each direction.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advanceLeftDown()
{
    // half of the hypotenuse
    this->move(-3.53,3.53);
}

/**********************************************************************/
/*! Moves the PlayerShip Left and Up diagonally equal to 5 pixels each direction.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advanceLeftUp()
{
    // half of the hypotenuse
    this->move(-3.53,-3.53);
}

/**********************************************************************/
/*! Moves the PlayerShip right 5 pixels.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advanceRight()
{
    this->move(5,0);
}

/**********************************************************************/
/*! Moves the PlayerShip Right and Down diagonally equal to 5 pixels each direction.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advanceRightDown()
{
    this->move(3.53,3.53);
}

/**********************************************************************/
/*! Moves the PlayerShip Right and Up diagonally equal to 5 pixels each direction.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advanceRightUp()
{
    this->move(3.53,-3.53);
}

/**********************************************************************/
/*! Moves the PlayerShip up 5 pixels.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advanceUp()
{
    this->move(0,-5);
}

/**********************************************************************/
/*! Moves the PlayerShip down 5 pixels.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::advanceDown()
{
       this->move(0,5);
}

/**********************************************************************/
/*! Currently under construction.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::shootGun()
{

}

/**********************************************************************/
/*! Currently under construction.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::shootSBomb()
{
}

/**********************************************************************/
/*! Currently under construction.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::shootBBomb()
{
}

/**********************************************************************/
/*! Returns the amoung of shield the PlayerShip has.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
int PlayerShip::getShield()
{
    return shipShield;
}

/**********************************************************************/
/*! Sets the amount of shield the PlayerShip has equal to theShield.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::setShield(int theShield)
{
    PlayerShip::shipShield = theShield;
}

 int PlayerShip::type() const
 {
    // Enable the use of qgraphicsitem_cast with this item.
    return Type;
 }
