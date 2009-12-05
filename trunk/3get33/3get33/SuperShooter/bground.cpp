/** File: BGround.cpp
  * Header: BGround.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: This class is used to create and manage the scrolling background.
  */
#include "bground.h"

/**********************************************************************/
/*! Constructor for the scrolling background object
 *
 *  Default constructor that sets the zvalue low enough to be below other items but above the scene
 *
 *  Author: Karan Chakrapani
 */
BGround::BGround()
{
    this->setZValue(5);
}

/**********************************************************************/
/*! Deconstructor for BGrouns object
 *
 *  Author: Karan Chakrapani
 */
BGround::~BGround()
{
}

/**********************************************************************/
/*! Bounding rectangle for the BGround object
 *
 *  Author: Karan Chakrapani
 */
QRectF BGround::boundingRect() const
{
    return QRectF(0,0,600,960);
}

/**********************************************************************/
/*! Returns the painter path for the BGround object
 *
 *  Author: Karan Chakrapani
 */
QPainterPath BGround::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 600,960);
    return path;
}

/**********************************************************************/
/*! Paints the BGround object
 *
 *  Author: Karan Chakrapani
 */
void BGround::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

        //Draws the BGround object.
        painter->drawImage(0,0, QImage(":/images/LargeBG.png"));
}
