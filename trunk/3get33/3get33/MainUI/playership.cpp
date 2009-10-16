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
    this->setArmor(100);
    this->setShield(100);
    this->setLives(3);
    this->setImage(QImage(":/images/GoodGuy.png"));
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
void PlayerShip::advance()
{
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
    if ( gunType == 0 )
    {
    }
    if ( gunType == 1 )
    {
    }
    if ( gunType == 2 )
    {
    }
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

