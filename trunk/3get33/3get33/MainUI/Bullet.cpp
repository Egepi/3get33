#include "Bullet.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

void Bullet::setImage(QImage theImage)
{
    Bullet::bulletImage = theImage;
}

void Bullet::move(qreal xMove, qreal yMove)
{
    qreal x_ = this->x();
    qreal yLoc = this->y();

    //Checks if the object is within the x-axis bounds of the gameScene
    if(( this->x() + xMove >= 0 )&&( this->x() + xMove <= 520 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the x-axis as determined from xMove.
        xLoc += xMove;
    }

    //Checks if the object is within the y-axis bounds of the gameScene
    if(( this->y() + yMove >= 0 )&&( this->y() + yMove <= 400 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the y-axis as determined from yMove.
        yLoc += yMove;
    }

    setPos(xLoc, yLoc); //Sets the new position of the object.
}

void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget)
    {

        // For the fun of it, I am going to make the character turn
        // Red when it detects it has collided with something else.
        // listOfCollidingItems returns a QList of items that you
        // can later traverse to examine what collided with the character.
       // QList<QGraphicsItem*> listOfCollidingItems = collidingItems();

        // If nothing collided then draw the character in black, otherwise red.
       // if (listOfCollidingItems.isEmpty()) painter->setBrush(Qt::black);
       // else painter->setBrush(Qt::red);


        // Draw the character as an ellipse
        painter->drawEllipse(-22,-22, 44,44);
        painter->drawPixmap(-20,-20,WhiteBullet.png);
    }
