#include "BasicShip.h"

#include <QGraphicsItem>
#include <iostream>
#include <QPixmap>
 #include <QPainter>

using namespace std;

BasicShip::BasicShip(int theArmor, int theShield, int theLives, QImage theImage)
{
    shipArmor = theArmor;
    shipShield = theShield;
    shipLives = theLives;
    shipImage = theImage;
}

BasicShip::BasicShip()
{
    BasicShip::xLoc = 0;
    BasicShip::yLoc = 0;
}

int BasicShip::getArmor()
{
    return shipArmor;
}

int BasicShip::getShield()
{
    return shipShield;
}

int BasicShip::getLives()
{
    return shipLives;
}

void BasicShip::setArmor(int theArmor)
{
    BasicShip::shipArmor = theArmor;
}

void BasicShip::setShield(int theShield)
{
    BasicShip::shipShield = theShield;
}

void BasicShip::setLives(int theLives)
{
    BasicShip::shipLives = theLives;
}

void BasicShip::setImage(QImage theImage)
{
    BasicShip::shipImage = theImage;
}
void BasicShip::setLoc(int x, int y)
{
    BasicShip::xLoc = x;
    BasicShip::yLoc = y;
}

QRectF BasicShip::boundingRect() const
{
    return QRectF(0,0,80,80);
}
QPainterPath BasicShip::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}

void BasicShip::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawImage(xLoc,yLoc, shipImage);
}
