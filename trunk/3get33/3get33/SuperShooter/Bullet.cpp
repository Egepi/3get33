#include "Bullet.h"


/**********************************************************************/
/*! Blank Constructor for Bullet
 *
 * Author: Jennifer Kinahan
 *
 */
Bullet::Bullet()
{
}

/**********************************************************************/
/*! Constructor for Bullet
 *
 * Author: Jennifer Kinahan
 *
 */
Bullet::Bullet(qreal locX, qreal locY, QImage bullImage, bool theOwner)
{
    bulletImage = bullImage;
    owner = theOwner;
    setPos(locX, locY);
    score = 0;
    this->setZValue(40);
}
/**********************************************************************/
/*! Destructor for Bullet
 *
 * Author: Jennifer Kinahan
 *
 */
Bullet::~Bullet()
{

}

/**********************************************************************/
/*! Draws Bullet on the Screen
 *
 * Author: Jennifer Kinahan
 *
 */
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //draws the bullet to the screen
    painter->drawImage(0,0, bulletImage);
}

/**********************************************************************/
/*! Creates bounding rectangle of the bullet
 *
 * Author: Jennifer Kinahan
 *
 */
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

/**********************************************************************/
/*!
 * Draws the bullet to the screen, sets the bounding rectangle of bullet.
 * Also moves bullet, updates and returns the score.  Returns the score
 * and type.
 *
 * Author: Jennifer Kinahan
 *
 */
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

 bool Bullet::getOwner()
 {
     return this->owner;
 }

 void Bullet::updateScore(int value)
 {
     this->score = this->score + value;

 }

 int Bullet::getScore()
 {
     return this->score;
 }
