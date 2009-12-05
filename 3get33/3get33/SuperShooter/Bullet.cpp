/** File: Bullet.cpp
  * Header: Bullet.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: The Bullet class' purpose is to draw a bullet on the screen  and
  *          shoot it across the screen.  It also updates score and holds data
  *          for the owner.
  */

#include "Bullet.h"
/**********************************************************************/
/*! Blank Constructor for a Bullet object.
 *
 * Author: Jennifer Kinahan
 */
Bullet::Bullet()
{
}

/**********************************************************************/
/*! Constructor for a Bullet object with values to be passed.
 *
 * Author: Jennifer Kinahan
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
/*! Destructor for a Bullet object.
 *
 * Author: Jennifer Kinahan
 */
Bullet::~Bullet()
{

}

/**********************************************************************/
/*! Draws Bullet on the Screen
 *
 * Author: Jennifer Kinahan
 */
void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //draws the bullet to the screen
    painter->drawImage(0,0, bulletImage);
}

/**********************************************************************/
/*! Creates bounding rectangle of the Bullet
 *
 * Author: Jennifer Kinahan
 */
QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,8,8);
}
/**********************************************************************/
/*! Sets the type of shape that the Bullet's image will be drawn under.
 *
 * This is a virtual function nessecary to be
 * implemented for all QGraphicsItems
 *
 * Author: Jennifer Kinahan
 */
QPainterPath Bullet::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 8, 8);
    return path;
}

/**********************************************************************/
/*! Responsible for moving the bullet on the scene
 *
 * Draws the bullet to the screen, sets the bounding rectangle of bullet.
 * Also moves bullet, updates and returns the score.  Returns the score
 * and type.
 *
 * Author: Jennifer Kinahan
 */
void Bullet::advance(int phase)
{
    if(!phase) return;
    qreal xLoc = this->x();
    qreal yLoc = this->y();
    qreal yMove = 0;
    if(owner == true)
    {//The bullet was shot from the PlayerShip
        yMove = -10;
    }
    else
    {//The bullet was shot from an enemy ship or BossShip
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
    {//Delete the bullet from memory
        this->~Bullet();
    }

    //Checks if the object is within the y-axis bounds of the gameScene
    if(( this->y() + yMove >= 0 )&&( this->y() + yMove <= 472 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the y-axis as determined from yMove.
        yLoc += yMove;
    }

    else
    {//Delete the bullet from memory
        this->~Bullet();
    }
    setPos(xLoc, yLoc);
}

 /**********************************************************************/
/*! This function returns the type used for type casting and for collision detection
  *
  * Author: Karan Chakrapani
  */
 int Bullet::type() const
 {
    // Enable the use of qgraphicsitem_cast with this item.
    return Type;
 }

 /**********************************************************************/
 /*! This function returns the owner of the bullet
  *
  * Author: Karan Chakrapani
  */
 bool Bullet::getOwner()
 {
     return this->owner;
 }

 /**********************************************************************/
 /*! This function updates this bullets score from collision detection
  *
  * Author: Karan Chakrapani
  */
 void Bullet::updateScore(int value)
 {
     this->score = this->score + value;

 }

/**********************************************************************/
 /*! This function returns the score caused by this bullet
  *
  * Author: Karan Chakrapani
  */
 int Bullet::getScore()
 {
     return this->score;
 }
