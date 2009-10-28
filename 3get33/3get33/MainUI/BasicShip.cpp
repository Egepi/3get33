#include "BasicShip.h"
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>


/**********************************************************************/
/*! Constructor for BasicShip.
 *
 *  This constructor only accepts an integer to set the shipArmor and
 *  shipLives because they are the only universal properties among the
 *  different types of ship in the game.
 *
 * Author: Todd Silvia
 */
BasicShip::BasicShip(int theArmor, int theLives, QImage theImage, int theX, int theY)
{
    BasicShip::shipArmor = theArmor;
    BasicShip::shipLives = theLives;
    BasicShip::shipImage = theImage;
    setPos(theX, theY);

}

/**********************************************************************/
/*! A blank constructor for BasicShip.
 */
BasicShip::BasicShip()
{
}

/**********************************************************************/
/*! A deconstructor for BasicShip.
 */
BasicShip::~BasicShip()
{
    delete this;
}

/**********************************************************************/
/*! Returns the amount of armor the given ship has, as an int
 *
 * Author: Todd Silvia
 */
int BasicShip::getArmor()
{
    return shipArmor;
}

/**********************************************************************/
/*! Returns the number of lives of given BasicShip object.
 *
 * Author: Todd Silvia
 */
int BasicShip::getLives()
{
    return shipLives;

}
/**********************************************************************/
/*! Sets the number of lives of the given ship equal to theLives.
 *
 * Author: Todd Silvia
 */
void BasicShip::setLives( int theLives )
{
    BasicShip::shipLives = theLives;
}

/**********************************************************************/
/*! Sets the given BasicShip 's shipArmor equal to theArmor.
 *
 * Author: Todd Silvia
 */
void BasicShip::setArmor(int theArmor)
{
    BasicShip::shipArmor = theArmor;
}

/**********************************************************************/
/*! Sets the image to be displayed for the ship in gameScene.
 *
 *  Note: The image generally has to be a of type
 *  .png inorder for the picture to have a tansparent
 *  background.
 *
 *  Author: Karan Chakrapani
  */
void BasicShip::setImage(QImage theImage)
{
    BasicShip::shipImage = theImage;
}

/**********************************************************************/
/*! Moves the BasicShip a number of pixels based on the value of xMove & yMove passed in.
 *
 *  This is the generic move method for all BasicShip.\n
 *  This method also takes into account the bounds of
 *  gameScene.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void BasicShip::move(qreal xMove, qreal yMove)
{
    qreal xLoc = this->x();
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

/**********************************************************************/
/*! Sets the bounding rectangle of the BasicShip which is used in collision detection.
 *
 *  Author: Karan Chakrapani,
 *          Todd Silvia
 */
QRectF BasicShip::boundingRect() const
{
    return QRectF(0,0,80,80);
}

/**********************************************************************/
/*! Sets the type of shape that the BasicShip 's image will be drawn under.
 *
 * This is a virtual function nessecary to be
 * implemented for all QGraphicsItems
 *
 *  Author: Karan Chakrapani,
 *          Todd Silvia
 */
QPainterPath BasicShip::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 80, 80);
    return path;
}

/**********************************************************************/
/*! A virtual function from QGraphcisItem that must be implemented to draw the object.
 *
 *  Pass the object the location to draw and the image
 *  to draw.
 *
 *  Author: Karan Chakrapani,
 *          Todd Silvia
 */
void BasicShip::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //Draws the BasicShip object.
    painter->drawImage(0,0, shipImage);
}

 void BasicShip::advance(int phase)
 {
     if(!phase) return;

     qreal asdf = 5;
     qreal xLoc = this->x();
     qreal yLoc = this->y();

    //Checks if the object is within the y-axis bounds of the gameScene
    if(( this->y() + asdf >= 0 )&&( this->y() + asdf <= 400 ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the y-axis as determined from yMove.
        yLoc += asdf;
    }
    setPos(xLoc, yLoc);

}
