#include "Bullet.h"

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

Bullet::Bullet()
{
}

Bullet::Bullet(qreal shipX, qreal shipY, QImage bullImage, bool theOwner)
{
    bulletImage = bullImage;
    owner = theOwner;
    this->setGraphicType(4);
    if(owner == true)
    {
        setPos(shipX+36, shipY-9);
    }
    else
    {
        setPos(shipX+18, shipY+49);
    }
}

Bullet::~Bullet()
{

}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //draws the bullet to the screen
    painter->drawImage(0,0, bulletImage);
}

void Bullet::setBulletImage(QImage theBulletImage)
{
    Bullet::bulletImage = theBulletImage;
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,8,8);
}

QPainterPath Bullet::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 8, 8);
    return path;
}

void Bullet::advance(int phase)
{
    if(!phase) return;
    qreal xLoc = this->x();
    qreal yLoc = this->y();
    qreal yMove = 0;
    if(owner == true)
    {
        yMove = -10;
    }
    else
    {
        yMove = 10;
    }

    qreal xMove = 0;
    //Checks if the object is within the x-axis bounds of the gameScene
    if(( this->x() + xMove >= 0 )&&( this->x() + xMove <= 592 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the x-axis as determined from xMove.
        xLoc += xMove;
    }

    else
    {
        this->~Bullet();
    }

    //Checks if the object is within the y-axis bounds of the gameScene
    if(( this->y() + yMove >= 0 )&&( this->y() + yMove <= 472 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the y-axis as determined from yMove.
        yLoc += yMove;
    }

    else
    {
        this->~Bullet();
    }
    setPos(xLoc, yLoc);
}

 int Bullet::type() const
 {
    // Enable the use of qgraphicsitem_cast with this item.
    return Type;
 }

//void Bullet::shoot()
//{

//}