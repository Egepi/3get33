#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMessageBox>
#include <QSound>
#include "BasicShip.h"


class PlayerShip : public BasicShip
{
    public:
        PlayerShip();
        ~PlayerShip();

        void PlayerShip::setLFlag( bool );
        void PlayerShip::setRFlag( bool );
        void PlayerShip::setDFlag( bool );
        void PlayerShip::setUFlag( bool );
        void PlayerShip::setShootGunFlag( bool );
        void PlayerShip::setShootSMissileFlag( bool );
        void PlayerShip::setShootBMissileFlag( bool );
        void PlayerShip::setShield(int theShield);
        void PlayerShip::setsMissile(int sMissile);
        void PlayerShip::setbMissile(int bMissile);
        void PlayerShip::setShieldMax(int value);
        void PlayerShip::setArmorMax(int value);

        int PlayerShip::getShield();
        int PlayerShip::getsMissile();
        int PlayerShip::getbMissile();
        bool PlayerShip::getShootGunFlag();
        bool PlayerShip::getShootSMissileFlag();
        bool PlayerShip::getShootBMissileFlag();

        enum { Type = 65536 + 2 };
        int PlayerShip::type() const;
        void PlayerShip::collCheck();

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
        int shieldMax;
        int armorMax;

        void PlayerShip::damage(int dTaken);
        void PlayerShip::advance(int phase);



};

#endif // PLAYERSHIP_H

