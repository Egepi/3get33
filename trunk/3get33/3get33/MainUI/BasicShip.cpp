#include "BasicShip.h"

#include <QGraphicsItem>
#include <iostream>
#include <QPixmap>
#include <QPainter>

using namespace std;

BasicShip::BasicShip(int theArmor, int theShield, qreal theX, qreal theY)
 {
    shipArmor = theArmor;
    shipShield = theShield;
    this->setPos(theX,theY);
}

BasicShip::BasicShip()
{

}


int BasicShip::getArmor()
{
    return shipArmor;
}

int BasicShip::getShield()
{
    return shipShield;
}


void BasicShip::setArmor(int theArmor)
{
    BasicShip::shipArmor = theArmor;
}

void BasicShip::setShield(int theShield)
{
    BasicShip::shipShield = theShield;
}



void BasicShip::setImage(QImage theImage)
{
    BasicShip::shipImage = theImage;
}
void BasicShip::move(qreal xMove, qreal yMove)
{
    //if( this->x() >= 0 )
    //{
        qreal xLoc = this->x() + xMove;
        qreal yLoc = this->y() + yMove;
        setPos(xLoc, yLoc);
    //}
}

QRectF BasicShip::boundingRect() const
{
    return QRectF(0,0,80,80);
}
QPainterPath BasicShip::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 80, 80);
    return path;
}

void BasicShip::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawImage(0,0, shipImage);
}
