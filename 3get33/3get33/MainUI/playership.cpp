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

void PlayerShip::advanceLeft()
{
    this->move(-5,0);
}
void PlayerShip::advanceRight()
{
    this->move(5,0);
}
void PlayerShip::advanceUp()
{
    this->move(0,-5);
}
void PlayerShip::advanceDown()
{
    this->move(0,5);
}
