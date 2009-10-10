#include "playership.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QPainter>
#include <iostream>
#include "BasicShip.h"
#include <QPushButton>

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

void PlayerShip::setLFlag( bool keyPress )
{
    lFlag = keyPress;
}
void PlayerShip::setRFlag( bool keyPress )
{
    rFlag = keyPress;
}
void PlayerShip::setDFlag( bool keyPress )
{
    dFlag = keyPress;
}
void PlayerShip::setUFlag( bool keyPress )
{
    uFlag = keyPress;
}

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
void PlayerShip::advanceLeft()
{
    this->move(-5,0);
}
void PlayerShip::advanceLeftDown()
{
    // half of the hypotenuse
    this->move(-3.53,3.53);
}
void PlayerShip::advanceLeftUp()
{
    // half of the hypotenuse
    this->move(-3.53,-3.53);
}
void PlayerShip::advanceRight()
{
    this->move(5,0);
}
void PlayerShip::advanceRightDown()
{
    this->move(3.53,3.53);
}
void PlayerShip::advanceRightUp()
{
    this->move(3.53,-3.53);
}
void PlayerShip::advanceUp()
{
    this->move(0,-5);
}
void PlayerShip::advanceDown()
{
       this->move(0,5);
}

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

void PlayerShip::shootSBomb()
{
}

void PlayerShip::shootBBomb()
{
}

int PlayerShip::getLives()
{
    return shipLives;
}

void PlayerShip::setLives( int theLives )
{
    PlayerShip::shipLives = theLives;
}

