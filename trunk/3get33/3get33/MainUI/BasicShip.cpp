#include "BasicShip.h"

BasicShip::BasicShip(int theArmor, int theShield, int theLives)
{
    shipArmor = theArmor;
    shipShield = theShield;
    shipLives = theLives;
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
QRectF BasicShip::boundingRect() const
 {
     qreal adjust = 0.5;
     return QRectF(-18 - adjust, -22 - adjust,
                   36 + adjust, 60 + adjust);
 }
 QPainterPath BasicShip::shape() const
 {
     QPainterPath path;
     path.addRect(-10, -20, 20, 40);
     return path;
 }
  void BasicShip::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
 {
 }
