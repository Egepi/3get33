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
    shootGunFlag = false;
    shootSMissileFlag = false;
    shootBMissileFlag = false;
    shieldMax = 100;
    armorMax = 100;
    this->setPos(260,400);
    this->setArmor(100);
    this->setShield(100);
    this->setLives(3);
    this->setImage(QImage(":/images/GoodGuy.png"));
    this->shipSizeX = 80;
    this->shipSizeY = 80;
    this->setsMissile(98);
    this->setbMissile(98);
    this->setZValue(50);
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

 void PlayerShip::collCheck()
 {
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();
    int decr = 0;

    if (!listOfCollidingItems.isEmpty())
    {
        int length = listOfCollidingItems.length();

        for (int i = 0; i < length; i++)
        {
            decr = 0;
            QGraphicsItem *item = listOfCollidingItems.at(i);
            if (item->isEnabled()==true)
            {
                //if a basic enemy ship
                if (item->type() == 65537)
                {
                    decr = 10;
                }
                //if a player ship
                if (item->type() == 65538)
                {
                    decr = 10;
                }
                //if a boss ship
                if (item->type() == 65539)
                {
                    decr = 30;
                }
                //if a bullet
                if (item->type() == 65540)
                {
                    decr = 10;
                    item->setPos(500,500);
                }
                //if big missile
                if (item->type() == 65541)
                {
                    decr = 50;
                    item->setPos(500,500);
                }
                //if small missile
                if (item->type() == 65542)
                {
                    decr = 25;
                    item->setPos(500,500);
                }
                //if shield powerup
                if (item->type() == 65543)
                {
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
                if (item->type() == 65544)
                {
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
                if (item->type() == 65545)
                {
                    if(this->getsMissile() < 99)
                    {
                        this->setsMissile(this->getsMissile()+1);

                    }
                    item->setPos(500,500);
                }
                //if big missile powerup
                if (item->type() == 65546)
                {
                    if(this->getbMissile() < 99)
                    {
                        this->setbMissile(this->getbMissile()+1);

                    }
                    item->setPos(500,500);
                }
                this->damage(decr);
            }
        }

    }
 }

 void PlayerShip::damage(int dTaken)
 {
     if (this->getShield() > 0)
     {
        this->setShield(this->getShield()-dTaken);
     }
     else if (this->getArmor() > 0)
     {
         this->setArmor(this->getArmor()-dTaken);
     }
     else if (this->getLives() > 0)
     {
         this->setLives(this->getLives()-1);
         this->setShield(this->shieldMax);
         this->setArmor(this->shieldMax);
     }
     else
     {
         this->hide();
         this->setEnabled(false);

         //this->setImage(QImage(":/images/explosion.png"));
         //this->move(0,0);

//         if(this->getLives() >= 0)
//         {
//            switch (QMessageBox::warning(0, "Continue ?",
//                            "Do you want to continue?",
//                            QMessageBox::No | QMessageBox::Default,
//                            QMessageBox::Yes | QMessageBox::Escape)) {
//           case QMessageBox::No:
//               break;
//            case QMessageBox::Yes:
//                break;
//           }
//        }
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

void PlayerShip::setShootGunFlag( bool keyPress )
{
    this->shootGunFlag = keyPress;
}

void PlayerShip::setShootSMissileFlag( bool keyPress )
{
    this->shootSMissileFlag = keyPress;
}

void PlayerShip::setShootBMissileFlag( bool keyPress )
{
    this->shootBMissileFlag = keyPress;
}
bool PlayerShip::getShootGunFlag()
{
    return this->shootGunFlag;
}
bool PlayerShip::getShootSMissileFlag()
{
    return this->shootSMissileFlag;
}
bool PlayerShip::getShootBMissileFlag()
{
    return this->shootBMissileFlag;
}
void PlayerShip::setShieldMax( int value )
{
    this->shieldMax = value;
}
void PlayerShip::setArmorMax( int value )
{
    this->armorMax = value;
}
