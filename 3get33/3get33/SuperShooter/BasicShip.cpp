/** File: BasicShip.cpp
  * Header: BasicShip.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: This class is used as a base class for all ships used in
  *          the SuperShooter game. This class contains properties that
  *          hold true for all space ships. This class is also used
  *          directly for the basic enemies.
  */
#include "BasicShip.h"


/**********************************************************************/
/*! Constructor for BasicShip.
 *
 *  This constructor only accepts an integer to set the shipArmor and
 *  shipLives because they are the only universal properties among the
 *  different types of ship in the game.
 *
 * Author: Todd Silvia
 */
BasicShip::BasicShip(int theArmor, int theLives, QImage theImage, int theX, int theY, int advancing)
{
    //Sets all of the variables to set up a BasicShip
    BasicShip::shipArmor = theArmor;
    BasicShip::shipLives = theLives;
    BasicShip::shipImage = theImage;
    setPos(theX, theY);
    damageCounter = 0;
    this->shipSizeX = 80;
    this->shipSizeY = 80;
    this->moveRight = true;
    this->setZValue(45);
    this->advanceType = advancing;

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
}

/**********************************************************************/
/*! Returns the amount of armor the given ship has, as an int.
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
    //Updates the armor for the BasicShip
    BasicShip::shipArmor = theArmor;
    //Tells the mainwindow that the armor has changed
    emit void armorChanged();
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
    if(( this->x() + xMove >= 0 )&&( this->x() + xMove <= 600 - this->shipSizeX ))
    {// The object was within the gameScene bounds so the ship is moved
     // along the x-axis as determined from xMove.
        xLoc += xMove;
    }

    //Checks if the object is within the y-axis bounds of the gameScene
    if(( this->y() + yMove >= 0 )&&( this->y() + yMove <= 480 - this->shipSizeY ))
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
    return QRectF(0,0,this->shipSizeX,this->shipSizeY);
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
    path.addRect(0, 0, this->shipSizeX, this->shipSizeY);
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

/**********************************************************************/
/*! Responsible for choosing either horizontal or diagonal movement.
  *
  * Diagonal moving was eventually abandoned, so the method currently only
  * calls the advance horizontal.
  *
  * Author: Karan Chakrapani
  */
 void BasicShip::advance(int phase)
 {
     if(!phase) return;
     //Return if the object is not enabled
     if(this->isEnabled()==false) return;
     //Checks collisions
     this->collCheck();

     if(this->advanceType == 1)
     {//Move the ship horizontally
         this->horizontalAdvance();
     }
     else if(this->advanceType == 2)
     {//Move the ship diagonally
         //NOTE: This abandoned before final version
         this->diagonalAdvance();
     }
     //Used inorder to implement further movement types
     //And also used for error checking incase advanceType is neither 1 or 2
     else
     {
     }
 }

/**********************************************************************/
/*! Determines the movement for all base BasicShip objects.
  *
  * This method is overridden for PlayerShip and BossShip. \n
  * Moves the basic enemy ships only by default. Checks for bounding
  * and then determines movement.
  *
  * Author: Karan Chakrapani,
  *         Todd Silvia
  */
 void BasicShip::horizontalAdvance()
 {
     qreal xDelta = 3;          //The amount of movement per method call
     qreal xLoc = this->x();    //Loads current x value of BasicShip
     qreal yLoc = this->y();    //Loads current y value of BasicShip

     if(this->moveRight == true)    //Begins to move right after being made by default
     {
         if((xLoc + xDelta + shipSizeX) <= SCENE_WIDTH)
         {//The ship is with in bounds so move right.
             this->setPos(xLoc + xDelta, yLoc);
         }
         else
         {//The ship is at the right edge of scene so move down instead
             this->setPos(xLoc, yLoc + shipSizeY);
             //Switch moveRight so that ship moves left on next call
             moveRight = false;
         }
     }
     else
     {//Ship is supposed to move left based on bool moveRight
         if((xLoc - xDelta) >= 0)
         {//Ship is within bounds so move the ship left
             this->setPos(xLoc - xDelta, yLoc);
         }
         else
         {//The ship is on the left edge of scene, so move down instead
             this->setPos(xLoc, yLoc + shipSizeY);
             //Switch moveRight so that ship moves right on next call
             moveRight = true;
         }
     }
 }

/**********************************************************************/
/*! Was orignally going to be used to move ship diagonally, but was later abandoned.
  *
  */
void BasicShip::diagonalAdvance()
{}

/**********************************************************************/
/*! This function returns the type used for type casting and for collision detection
  *
  * Author: Karan Chakrapani
  */
  int BasicShip::type() const
 {
    // Enable the use of qgraphicsitem_cast with this item.
    return Type;
 }

/**********************************************************************/
  /*! Resnposible detecting collisions with other ships, bullets, missiles
    *
    * This method uses the type enum to figure out what class the QGraphicsItem that is colliding
    * Different actions are performed when colliding with different objects
    * If there was damage to be taken after the collision checks it is done by calling the damage method
    *
    * Author: Karan Chakrapani
    */
 void BasicShip::collCheck()
 {
    //Retrive the list of colliding items
    QList<QGraphicsItem*> listOfCollidingItems = collidingItems();
    int decr = 0;
    //If nto colliding dont do anything
    if (!listOfCollidingItems.isEmpty())
    {
        int length = listOfCollidingItems.length();

        //For loop iteratign through the list of colliding items
        for (int i = 0; i < length; i++)
        {
            decr = 0;
            //get item at i in the list
            QGraphicsItem *item = listOfCollidingItems.at(i);
            if(item->isEnabled() ==true)
            {
                //if a player ship
                if (item->type() == 65538)
                {
                    //take 10 damage
                    decr = 10;
                }
                //if a bullet
                else if (item->type() == 65540)
                {
                    //cast to a bullet object
                    Bullet *abit = dynamic_cast<Bullet*> (item);
                    //chekc if the owner of the bullet is the player
                    if(abit->getOwner())
                    {
                        //update the score of the bullet for hitting
                        abit->updateScore(10);
                        //take 10 damage
                        decr = 10;
                        //"delete" bullet
                        item->setPos(500,500);
                    }

                }
                //If a big missile
                else if (item->type() == 65541)
                {
                    //cast to a missile object
                    Missile *bbit = dynamic_cast<Missile*> (item);
                    //chekc if missile is the player's
                    if(bbit->getOwner())
                    {
                        //take 50 damage
                        decr = 50;
                        //update the missile's score
                        bbit->updateScore(50);
                        //"delete" missile
                        item->setPos(500,500);
                    }

                }
                //If a small Missile
                else if (item->type() == 65542)
                {
                    //cast to a missile object
                    Missile *cbit = dynamic_cast<Missile*> (item);
                    //check if the owner is the player
                    if(cbit->getOwner())
                    {
                        //take 25 damage
                        decr = 25;
                        //update missile's score
                        cbit->updateScore(25);
                        //"delete" the missile
                        item->setPos(500,500);
                    }

                }
                //Other random objects we dont need to worry about
                else
                {
                }
                //if damage needs to be taken call damage with the value
                if(decr > 0)
                {
                    this->damage(decr);
                }
            }
        }

    }
 }

/**********************************************************************/
 /*! Deals damage to this ship based on what collision occured
   *
   * Author: Karan Chakrapani
   */
 void BasicShip::damage(int dTaken)
 {
     //deal damage to armor if we have armor
     if (this->getArmor() > 0)
     {
         //reduce armor by damage
         this->setArmor(this->getArmor()-dTaken);
         //If the ship goes below 0 armor stop making it interactable
         if (this->getArmor() <= 0)
         {
             //hide from view
             this->hide();
             //make it non movable and interactable
             this->setEnabled(false);
         }
     }
 }



