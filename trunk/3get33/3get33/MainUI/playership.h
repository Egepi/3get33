#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include "BasicShip.h"

class PlayerShip : public BasicShip
{
    public:
        PlayerShip();
        ~PlayerShip();
        void PlayerShip::advance(int phase);
        void PlayerShip::setLFlag( bool );
        void PlayerShip::setRFlag( bool );
        void PlayerShip::setDFlag( bool );
        void PlayerShip::setUFlag( bool );
        void PlayerShip::setShootGunFlag( bool );
        void PlayerShip::setShootSMissileFlag( bool );
        void PlayerShip::setShootBMissileFlag( bool );
        void PlayerShip::advanceLeft();
        void PlayerShip::advanceLeftDown();
        void PlayerShip::advanceLeftUp();
        void PlayerShip::advanceRight();
        void PlayerShip::advanceRightDown();
        void PlayerShip::advanceRightUp();
        void PlayerShip::advanceUp();
        void PlayerShip::advanceDown();
        void PlayerShip::setShield(int theShield);
        int PlayerShip::getShield();
        enum { Type = 65536 + 2 };
        int PlayerShip::type() const;
        void PlayerShip::collCheck();
        void PlayerShip::damage(int dTaken);
        void PlayerShip::setsMissile(int sMissile);
        int PlayerShip::getsMissile();
        void PlayerShip::setbMissile(int bMissile);
        int PlayerShip::getbMissile();




    private:
        /*! The amount of shield the ship has. */
        int shipShield;
        /*! Number of small bombs the ship has. */
        int sMissile;
        /*! Number of big bombs the ship has. */
        int bMissile;
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
        bool shootGunFlag;
        bool shootSMissileFlag;
        bool shootBMissileFlag;


};

#endif // PLAYERSHIP_H

