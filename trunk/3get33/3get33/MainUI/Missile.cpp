#include "Missile.h"


Missile::Missile()
{
}

Missile::Missile(qreal locX, qreal locY, QImage missImage, bool theOwner, bool big)
{
    bigMissile = big;
    MissileImage = missImage;
    owner = theOwner;
    setPos(locX, locY);
    score = 0;
    this->setZValue(10);
}

Missile::~Missile()
{

}

void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //draws the Missile to the screen
    painter->drawImage(0,0, MissileImage);
}

QRectF Missile::boundingRect() const
{
    if (this->bigMissile == false)
    {
        return QRectF(0,0,10,20);
    }
    else
    {
        return QRectF(0,0,20,40);
    }
}

QPainterPath Missile::shape() const
{
    if (this->bigMissile == false)
    {
        QPainterPath path;
        path.addRect(0, 0, 10, 20);
        return path;
    }
    else
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 40);
        return path;
    }
}

void Missile::advance(int phase)
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
        this->~Missile();
    }

    //Checks if the object is within the y-axis bounds of the gameScene
    if(( this->y() + yMove >= 0 )&&( this->y() + yMove <= 472 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the y-axis as determined from yMove.
        yLoc += yMove;
    }

    else
    {
        this->~Missile();
    }
    setPos(xLoc, yLoc);
}

 int Missile::type() const
 {
    // Enable the use of qgraphicsitem_cast with this item.
     if(this->bigMissile)
     {
         return Type;
     }
     else
     {
         return Type + 1;
     }
 }

 bool Missile::getOwner()
 {
     return this->owner;
 }

 void Missile::updateScore(int value)
 {
     this->score = this->score + value;

 }

 int Missile::getScore()
 {
     return this->score;
 }

