/** File: PowerUp.cpp
  * Header: PowerUp.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: This class is used to create and manage the 4 different
  *          kinds of power ups implemented in the SuperShooter game.
  */
#include "PowerUp.h"

/**********************************************************************/
/*! Missile Constructor
 *
 * Creates different powerups that help the player in different ways
 *
 * Author: Jennifer Kinahan
 */

PowerUp::PowerUp()
{
    //power up type 1 = shield
    //power up type 2 = health
    //power up type 3 = small missile
    //power up type 4 = big missile
    puType = (qrand() % 4) +1;
    puLocX = qrand() % 560;
    puLocY = qrand() % 440;
    setPos(puLocX, puLocY);
    //sheild
    if(this->puType == 1 )
    {
        puImage = QImage(":/images/shieldpowerup.gif");
    }
    //armor
    else if(this->puType == 2 )
    {
        puImage = QImage(":/images/health.gif");
    }
    //small missile
    else if(this->puType == 3 )
    {
        puImage = QImage(":/images/purpleDS.png");
    }
    //big missile
    else if(this->puType == 4 )
    {
        puImage = QImage(":/images/greenDM.png");
    }
    //sheild if nothing
    else
    {
        puImage = QImage(":/images/shieldpowerup.gif");
    }
    this->setZValue(10);
}

/**********************************************************************/
/*! Missile Deconstructor
 *
 * Author: Jennifer Kinahan
 */

PowerUp::~PowerUp()
{
}

/*! Paints missile on the scene
 *
 * Author: Jennifer Kinahan
 */
/**********************************************************************/
void PowerUp::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //draws the power up to the screen
    painter->drawImage(0, 0, puImage);
}

/**********************************************************************/
/*! Bounding rectangle for collision detection and drawing
 *
 * Creates different bounding rectangles for diffeerent powerups
 *
 * Author: Jennifer Kinahan
 */

QRectF PowerUp::boundingRect() const
{
    //if shield
    if(this->puType == 1 )
    {
        return QRectF(0,0,20,20);
    }
    //if armor
    else if(this->puType == 2 )
    {
        return QRectF(0,0,20,20);
    }
    //if small missile
    else if(this->puType == 3 )
    {
        return QRectF(0,0,15,38);
    }
    //if big missile
    else if(this->puType == 4 )
    {
        return QRectF(0,0,15,38);
    }
    //sheild if nothing
    else
    {
        return QRectF(0,0,20,20);
    }
}

/**********************************************************************/
/*! Eeturns the painter path for drawing the powerup
 *
 * Author: Jennifer Kinahan
 */
QPainterPath PowerUp::shape() const
{
    //if sheild
    if(this->puType == 1 )
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }
    //if armor
    else if(this->puType == 2 )
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }
    //if small missile
    else if(this->puType == 3 )
    {
        QPainterPath path;
        path.addRect(0, 0, 15, 38);
        return path;
    }
    //if big missile
    else if(this->puType == 4 )
    {
        QPainterPath path;
        path.addRect(0, 0, 15, 38);
        return path;
    }
    //sheild if no type
    else
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }

}

/**********************************************************************/
/*! Function used for type castng and figuring out proper type in collision detection
 *
 * Author: Jennifer Kinahan
 */
int PowerUp::type() const
{
   // Enable the use of qgraphicsitem_cast with this item.
    //if sheild
    if(this->puType == 1 )
    {
        return Type;
    }
    //if armor
    else if(this->puType == 2 )
    {
        return Type + 1;
    }
    //if small missile
    else if(this->puType == 3 )
    {
        return Type + 2;
    }
    //if big missile
    else if(this->puType == 4 )
    {
        return Type + 3;
    }
    //sheild if nothing
    else
    {
        return Type;
    }
}

/**********************************************************************/
/*! Allows movement for Missiles
 *
 * Moves based on who the owner is, either player or enemy.
 *
 * Author: Jennifer Kinahan
 */
void PowerUp::advance(int phase)
{
    if(!phase) return;
    qreal xLoc = this->x();
    qreal yLoc = this->y();
    qreal yMove = 1;
    qreal xMove = 0;
    //Checks if the object is within the x-axis bounds of the gameScene
    if(( this->x() + xMove >= 0 )&&( this->x() + xMove <= 592 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the x-axis as determined from xMove.
        xLoc += xMove;
    }

    else
    {
        this->~PowerUp();
    }

    //Checks if the object is within the y-axis bounds of the gameScene
    if(( this->y() + yMove >= 0 )&&( this->y() + yMove <= 472 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the y-axis as determined from yMove.
        yLoc += yMove;
    }

    else
    {
        this->~PowerUp();
    }
    setPos(xLoc, yLoc);
}

