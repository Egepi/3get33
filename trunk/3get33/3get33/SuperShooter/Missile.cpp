/** File: Missile.cpp
  * Header: Missile.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: The Missile class' purpose is to draw a missile on the screen
  *         either big or small, and shoot it across the screen.  It also
  *         updates score and holds data for the owner.
  */

#include "Missile.h"

/**********************************************************************/
/*! Blank Constructor for Missile
 *
 * Author: Jennifer Kinahan
 */
Missile::Missile()
{
}

/**********************************************************************/
/*! Parameterized constructor for creating a missile
 *
 *
 * Author: Jennifer Kinahan
 */
Missile::Missile(qreal locX, qreal locY, QImage missImage, bool theOwner, bool big)
{
    bigMissile = big;
    MissileImage = missImage;
    owner = theOwner;
    setPos(locX, locY);
    score = 0;
    this->setZValue(10);
}

/**********************************************************************/
/*! Missile Deconstructor
 *
 * Author: Jennifer Kinahan
 */
Missile::~Missile()
{

}

/**********************************************************************/
/*! Missile paint function
 *
 * Draws the missile to the screen, sets the boundint rectangle of big and
 * small missiles.  Also moves either big or small missiles, updates and
 * returns the score.  Returns whether or not it is a large or small missile
 * and who the owner of the missile is.
 *
 * Author: Jennifer Kinahan
 */
void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //draws the Missile to the screen
    painter->drawImage(0,0, MissileImage);
}
/**********************************************************************/
/*! Creates bounding rectangle for big and small missiles used for collision detection
 *
 * Author: Jennifer Kinahan
 */
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
/**********************************************************************/
/*! Sets the type of shape that the BasicShip 's image will be drawn under.
 *
 * This is a virtual function nessecary to be
 * implemented for all QGraphicsItems
 *
 *  Author: Jennifer Kinahan
 */
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
/**********************************************************************/
/*! This funciton is responsible for moving the missile
 *
 * Moves the missile up or down based on if the player or the enemy ships shot it
 *
 * Author: Jennifer Kinahan
 */
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

/**********************************************************************/
/*! Determines the type of QGraphicsItem this is for collision detection.
 *
 * Author: Karan Chakrapani
 */
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

 /**********************************************************************/
 /*! Determines if the missile was shot from an enemy or player ship.
  *
  * Author: Todd Silvia,
  *         Karan Chakrapani,
  *         Jennifer Kinahan
  */
 bool Missile::getOwner()
 {
     return this->owner;
 }

 /**********************************************************************/
 /*! Update overall score for the game based on this missile being shot.
   *
   * Author: Karan Chakrapani
   */
 void Missile::updateScore(int value)
 {
     this->score = this->score + value;

 }

 /**********************************************************************/
 /*! Returns the current score based on this missle being shot.
   *
   * Author: Karan Chakrapani
   */
 int Missile::getScore()
 {
     return this->score;
 }

