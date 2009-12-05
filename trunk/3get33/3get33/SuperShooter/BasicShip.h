#ifndef BASICSHIP_H
#define BASICSHIP_H\

#include <QGraphicsItem>
#include <QPainter>
#include "Bullet.h"
#include "Missile.h"

class BasicShip : public QGraphicsItem
{
    public:
    BasicShip(int theArmor, int theLives, QImage theImage, int theX, int theY, int);
    BasicShip();
    ~BasicShip();
    int getArmor();
    int getLives();
    void setLives( int theLives );
    void setArmor(int theArmor);
    void setImage(QImage theImage);
    void setShipSizeX(int);
    void setShipSizeY(int);
    void move(qreal xMove, qreal yMove);
    enum { Type = 65536 + 1 };
    int type() const;
    int shipSizeX;
    int shipSizeY;
    void collCheck();

    signals:
         void armorChanged();

    private:
        /*! The amount of armor. */
        int shipArmor;
        /*! The amount of lives. */
        int shipLives;
        /*! The imgae drawn for this ship. */
        QImage shipImage;
        /*! How much damage you have done through out the whole level */
        int damageCounter;
        /*! Determines if the BasicShip should move right or left*/
        bool moveRight;
        /*! Sets the constant value of the gameScene 's width*/
        static const qreal SCENE_WIDTH = 600;
        /*! Sets the constant value of teh gameScene's height*/
        static const qreal SCENE_HEIGHT = 480;
        /*! Method to handle the movement of the BasicShip*/
        void advance(int phase);
        /*! Sets the bounding rectangle of the BasicShip for collisions*/
        QRectF boundingRect() const;
        /*! Virtual function to determine how to draw a QGraphicsItem*/
        QPainterPath shape() const;
        /*! Virtual function for all QGraphicsItems to help draw on screen*/
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        /*! Determines the type of movement of the BasicShip */
        int advanceType;
        /*! Handles the horizontal movement of the BasicShip*/
        void horizontalAdvance();
        /*! Handles the diagonal movement of the BasicShip*/
        void diagonalAdvance();
        /*! Calculates the amount of damage to be dealt to BasicShip since last call*/
        void damage(int dTaken);
};

#endif // BASICSHIP_H


