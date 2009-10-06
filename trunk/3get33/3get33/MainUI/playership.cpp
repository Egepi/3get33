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

void PlayerShip::keyPressEvent(QKeyEvent *key)
{
    switch(key->key())
    {
    case Qt::Key_Left:
       this->advanceLeft();
       break;
    case Qt::Key_Right:
       this->advanceRight();
       break;
    case Qt::Key_Up:
       this->advanceUp();
       break;
    case Qt::Key_Down:
       this->advanceDown();
       break;
    }
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
