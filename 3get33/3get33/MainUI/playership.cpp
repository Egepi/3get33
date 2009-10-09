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
    else if(( lFlag ) && ( dFlag ) && ( !rFlag ) && ( !uFlag )){
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

