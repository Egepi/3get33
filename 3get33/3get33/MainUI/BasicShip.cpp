#include "BasicShip.h"

#include <QGraphicsItem>
#include <iostream>
#include <QPixmap>
#include <QPainter>

using namespace std;

/*!
 *
 */
BasicShip::BasicShip(int theArmor, qreal theX, qreal theY)
{
    shipArmor = theArmor;
    this->setPos(theX,theY);
}

/*!
 *
 */
BasicShip::BasicShip()
{

}

/*!
 *
 */
int BasicShip::getArmor()
{
    return shipArmor;
}

/*!
 *
 */
void BasicShip::setArmor(int theArmor)
{
    BasicShip::shipArmor = theArmor;
}

/*!
 *
 */
void BasicShip::setImage(QImage theImage)
{
    BasicShip::shipImage = theImage;
}
/*!
 *
 */
void BasicShip::move(qreal xMove, qreal yMove)
{
    qreal xLoc = this->x();
    qreal yLoc = this->y();
    if(( this->x() + xMove >= 0 )&&( this->x() + xMove <= 520 ))
    {
        xLoc += xMove;
    }
    if(( this->y() + yMove >= 0 )&&( this->y() + yMove <= 400 ))
    {
        yLoc += yMove;
    }
    setPos(xLoc, yLoc);
}
/*!
 *
 */
QRectF BasicShip::boundingRect() const
{
    return QRectF(0,0,80,80);
}
/*!
 *
 */
QPainterPath BasicShip::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 80, 80);
    return path;
}

/*!
 *
 */
void BasicShip::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawImage(0,0, shipImage);
}
