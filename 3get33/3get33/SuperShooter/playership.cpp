/** File: PlayerShip.cpp
  * Header: playership.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: This class extends BasicShip and is used to create the
  *          space ship that will be controlled by the user. Also
  *          Has overridden methods for movement among some other
  *          unique properties to a player controlled ship.
  */
#include "playership.h"


/**********************************************************************/
/*! Constructor for PlayerShip. Sets default characteristics.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 *          Todd Silvia
 */
PlayerShip::PlayerShip()
{
    //Sets default values.
    lFlag = false;
    rFlag = false;
    dFlag = false;
    uFlag = false;
    shootGunFlag = false;
    shootSMissileFlag = false;
    shootBMissileFlag = false;
    shieldMax = 100;
    armorMax = 100;
    this->setPos(260,400);
    this->setArmor(this->armorMax);
    this->setShield(this->shieldMax);
    this->setLives(3);
    this->setImage(QImage(":/images/GoodGuy.png"));
    this->shipSizeX = 80;
    this->shipSizeY = 80;
    this->setsMissile(10);
    this->setbMissile(10);
    this->setZValue(50);
    this->shipIsDead = false;
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
    if(!phase) return;
    if(reset>0)
    {
        reset--;
        return;
    }
    else
    {
        this->setImage(QImage(":/images/GoodGuy.png"));
        this->setEnabled(true);
    }

    if (this->isEnabled() == false) return;
    this->collCheck();

    //left movement
    if( (lFlag) && (!dFlag) && (!rFlag) && (!uFlag)  )
    {
        this->move(-5,0);
    }
    //right movement
    else if(( !lFlag ) && ( !dFlag ) && ( rFlag ) && ( !uFlag ))
    {
        this->move(5,0);
    }
    //down movement
    else if(( !lFlag ) && ( dFlag ) && ( !rFlag ) && ( !uFlag ))
    {
        this->move(0,5);
    }
    //up movement
    else if(( !lFlag ) && ( !dFlag ) && ( !rFlag ) && ( uFlag ))
    {
        this->move(0,-5);
    }
    //leftdown
    else if(( lFlag ) && ( dFlag ) && ( !rFlag ) && ( !uFlag ))
    {
        this->move(-3.53,3.53);
    }
    //left-up movement
    else if(( lFlag ) && ( uFlag ) && ( !rFlag ) && ( !dFlag ))
    {
        this->move(-3.53,-3.53);
    }
    //right-down movement
    else if(( rFlag ) && ( dFlag ) && ( !lFlag ) && ( !uFlag ))
    {
        this->move(3.53,3.53);
    }
    //right-up movement
    else if(( rFlag ) && ( uFlag ) && ( !lFlag ) && ( !dFlag ))
    {
        this->move(3.53,-3.53);
    }
}

/**********************************************************************/
/*! Returns the amount of shield the PlayerShip has.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 *          Todd Silvia
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
 *          Todd Silvia
 */
void PlayerShip::setShield(int theShield)
{
    PlayerShip::shipShield = theShield;
}

/**********************************************************************/
/*! Returns the type of QGraphicsItem for the use in collision detection.
 *
 * Author: Karan Chakrapani
 */
 int PlayerShip::type() const
 {
    // Enable the use of qgraphicsitem_cast with this item.
    return Type;
 }

 /**********************************************************************/
 /*! Checks Collision Detection for the player ship
  *
  * Author: Karan Chakrapani
  */
 void PlayerShip::collCheck()
 {
     //get the list of colliding items
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();
    int decr = 0;

    if (!listOfCollidingItems.isEmpty())
    {
        int length = listOfCollidingItems.length();

        for (int i = 0; i < length; i++)
        {
            decr = 0;
            //get the item at i
            QGraphicsItem *item = listOfCollidingItems.at(i);
            if (item->isEnabled()==true)
            {
                //if a basic enemy ship
                if (item->type() == 65537)
                {
                    decr = 10;
                }
                //if a boss ship
                else if (item->type() == 65539)
                {
                    decr = 30;
                }
                //if a bullet
                else if (item->type() == 65540)
                {
                    decr = 15;
                    item->setPos(500,500);
                }
                //if big missile
                else if (item->type() == 65541)
                {
                    decr = 50;
                    item->setPos(500,500);
                }
                //if small missile
                else if (item->type() == 65542)
                {
                    decr = 25;
                    item->setPos(500,500);
                }
                //if shield powerup
                else if (item->type() == 65543)
                {
                    //Increase sheild by up to 10 without going over the Sheild Max
                    if(this->getShield() < this->shieldMax - 10)
                    {
                        this->setShield(this->getShield()+10);
                        item->setPos(500,500);
                    }

                    else if(this->getShield() < this->shieldMax)
                    {
                        this->setShield(100);
                        item->setPos(500,500);
                    }
                    else
                    {
                        item->setPos(500,500);
                    }

                }
                //if armor powerup
                else if (item->type() == 65544)
                {
                    //Increase armor by up to 10 without going over the Armor Max
                    if(this->getArmor() < this->armorMax - 10)
                    {
                        this->setArmor(this->getArmor()+10);
                        item->setPos(500,500);
                    }
                    else if(this->getArmor() < this->armorMax)
                    {
                        this->setArmor(100);
                        item->setPos(500,500);
                    }
                    else
                    {
                        item->setPos(500,500);
                    }
                }
                //if small missile powerup
                else if (item->type() == 65545)
                {
                    //Increase amount of small missiles by 1 without going over 99
                    if(this->getsMissile() < 99)
                    {
                        this->setsMissile(this->getsMissile()+1);

                    }
                    item->setPos(500,500);
                }
                //if big missile powerup
                if (item->type() == 65546)
                {
                    //Increase amount of big missiles by 1 without going over 99
                    if(this->getbMissile() < 99)
                    {
                        this->setbMissile(this->getbMissile()+1);

                    }
                    item->setPos(500,500);
                }
                else
                {
                }
                //If colided with damaging enemy item then call damage
                if(decr > 0)
                {
                    this->damage(decr);
                }
            }
        }

    }
 }

 /**********************************************************************/
 /*! Inflict damage to the player ship's different systems
  *
  * Author: Karan Chakrapani
  */
 void PlayerShip::damage(int dTaken)
 {
     //if sheild has value
     if (this->getShield() > 0)
     {
        //if sheild hits 0 before all damage is applied
        if(this->getShield() - dTaken < 0)
        {
            dTaken = dTaken - this->getShield();\
            this->setShield(0);
            //if not enough armor to take damage
            if(this->getArmor()-dTaken <= 0)
            {
                this->setArmor(0);
                //if not enough lives game over
                if (this->getLives()-1 == 0)
                {
                    this->setShipIsDead(true);
                    this->setLives(0);
                    this->hide();
                    this->setEnabled(false);
                    this->setAllFlags(false);
                }\
                //take away a life and respawn
                else
                {
                    this->respawn();
                    this->setLives(this->getLives()-1);
                    this->setShield(this->shieldMax);
                    this->setArmor(this->armorMax);
                }
            }
            //apply damage down to armor
            else
            {
                this->setArmor(this->getArmor()-dTaken);
            }
        //apply damage to sheild
        }
        else
        {
            this->setShield(this->getShield()-dTaken);
        }
     }
     //same as above but without the sheild
     else if (this->getArmor() > 0)
     {
         if(this->getArmor()-dTaken <= 0)
         {
             this->setArmor(0);
             if (this->getLives()-1 == 0)
             {
                 this->setShipIsDead(true);
                 this->setLives(0);
                 this->hide();
                 this->setEnabled(false);
                 this->setAllFlags(false);
             }
             else
             {
                 this->respawn();
                 this->setLives(this->getLives()-1);
                 this->setShield(this->shieldMax);
                 this->setArmor(this->armorMax);
             }
         }
         else
         {
             this->setArmor(this->getArmor()-dTaken);
         }
     }
     //same as above but without armor
     else if(this->getLives()>0)
     {
         if (this->getLives()-1 == 0)
         {
             this->setShipIsDead(true);
             this->setLives(0);
             this->hide();
             this->setEnabled(false);
             this->setAllFlags(false);
         }
         else
         {
             this->respawn();
             this->setLives(this->getLives()-1);
             this->setShield(this->shieldMax);
             this->setArmor(this->armorMax);
         }
     }
     //same as above with only death
     else
     {
         this->hide();
         this->setEnabled(false);
         this->setAllFlags(false);
     }
 }


/**********************************************************************/
/*! Returns the amoung of sMissiles the PlayerShip has.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
int PlayerShip::getsMissile()
{
    return sMissile;
}

/**********************************************************************/
/*! Sets the amount of shield the PlayerShip has equal to theShield.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::setsMissile(int thesMissile)
{
    PlayerShip::sMissile = thesMissile;
}


/**********************************************************************/
/*! Sets the amount of bMissile the PlayerShip has equal to theShield.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void PlayerShip::setbMissile(int thebMissile)
{
    PlayerShip::bMissile = thebMissile;
}


/**********************************************************************/
/*! Returns the amoung of shield the PlayerShip has.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
int PlayerShip::getbMissile()
{
    return bMissile;
}

/**********************************************************************/
/*! Set the Shoot Gun flag
 *
 * Author: Karan Chakrapani
 */
void PlayerShip::setShootGunFlag( bool keyPress )
{
    this->shootGunFlag = keyPress;
}

/**********************************************************************/
/*! Set the Shoot Small Missile flag
 *
 * Author: Karan Chakrapani
 */
void PlayerShip::setShootSMissileFlag( bool keyPress )
{
    this->shootSMissileFlag = keyPress;
}

/**********************************************************************/
/*! Set the shoot Big Missile Flag
 *
 * Author: Karan Chakrapani
 */
void PlayerShip::setShootBMissileFlag( bool keyPress )
{
    this->shootBMissileFlag = keyPress;
}

/**********************************************************************/
/*! Return the Shoot Gun flag value
 *
 * Author: Karan Chakrapani
 */
bool PlayerShip::getShootGunFlag()
{
    return this->shootGunFlag;
}

/**********************************************************************/
/*! Return the Shoot Small Missile Flag
 *
 * Author: Karan Chakrapani
 */
bool PlayerShip::getShootSMissileFlag()
{
    return this->shootSMissileFlag;
}

/**********************************************************************/
/*! Return the Shoot Big Missile Flag
 *
 * Author: Karan Chakrapani
 */
bool PlayerShip::getShootBMissileFlag()
{
    return this->shootBMissileFlag;
}

/**********************************************************************/
/*! For use in loading a level file. It sets the max possible shield.
 *
 * Author: Todd Silvia
 */
void PlayerShip::setShieldMax( int value )
{
    this->shieldMax = value;
}

/**********************************************************************/
/*! For use in loading a level file. It sets the max possible armor.
 *
 * Author: Todd Silvia
 */
void PlayerShip::setArmorMax( int value )
{
    this->armorMax = value;
}

/**********************************************************************/
/*! Returns the bool value of if the PlayerShip is dead or not.
 *
 * Author: Todd Silvia
 */
bool PlayerShip::isShipDead()
{
    return this->shipIsDead;
}

/**********************************************************************/
/*! Sets the boolean value of if the PlayerShip still has more lives or not.
 *
 * Author: Todd Silvia
 */
void PlayerShip::setShipIsDead(bool shipLife)
{
    this->shipIsDead = shipLife;
}

/**********************************************************************/
/*! Respawns the player ship
 *
 * Explode the ship then reset it back to startign location. Also play death sound
 *
 * Author: Karan Chakrapani
 */
void PlayerShip::respawn()
{
    this->setImage(QImage(":/images/explosion.png"));
    this->setEnabled(false);
    this->setPos(260,400);
    reset = 25;
    QSound::play(QString("exit.wav"));
    this->setAllFlags(false);
}

/**********************************************************************/
/*! Reset all flags for the player ship in one method
 *
 * Author: Karan Chakrapani
 */
void PlayerShip::setAllFlags(bool flagger)
{
    this->setLFlag( flagger );
    this->setRFlag( flagger );
    this->setUFlag( flagger );
    this->setDFlag( flagger );
    this->setShootBMissileFlag(flagger);
    this->setShootSMissileFlag(flagger);
    this->setShootGunFlag(flagger);

}
