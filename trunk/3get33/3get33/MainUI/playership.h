#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include "BasicShip.h"

class PlayerShip : public BasicShip
{
    public:
        PlayerShip();
        void PlayerShip::advance();
        void PlayerShip::setLFlag( bool );
        void PlayerShip::setRFlag( bool );
        void PlayerShip::setDFlag( bool );
        void PlayerShip::setUFlag( bool );
        void PlayerShip::advanceLeft();
        void PlayerShip::advanceLeftDown();
        void PlayerShip::advanceLeftUp();
        void PlayerShip::advanceRight();
        void PlayerShip::advanceRightDown();
        void PlayerShip::advanceRightUp();
        void PlayerShip::advanceUp();
        void PlayerShip::advanceDown();
        void PlayerShip::shootGun();
        void PlayerShip::shootSBomb();
        void PlayerShip::shootBBomb();
        void PlayerShip::setShield(int theShield);
        int  PlayerShip::getShield();
    int PlayerShip::getShield();


    private:
        /*! The amount of shield the ship has. */
        int shipShield;
        /*! Number of small bombs the ship has. */
        int sBombs;
        /*! Number of big bombs the ship has. */
        int bBombs;
        /*! The type of gun the ship has as an integer. */
        int gunType;
        /*! Flag for ship moving left. */
        bool lFlag;
        /*! Flag for ship moving right. */
        bool rFlag;
        /*! Flag for ship moving down. */
        bool dFlag;
        /*! Flag for ship moving up. */
        bool uFlag;

};

#endif // PLAYERSHIP_H

