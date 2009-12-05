#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <QGraphicsItem>
#include <QPainter>
#include <QMessageBox>
#include <QSound>
#include <QTimer>
#include "BasicShip.h"

class PlayerShip : public BasicShip
{
    public:
        PlayerShip();
        ~PlayerShip();

        void setLFlag( bool );
        void setRFlag( bool );
        void setDFlag( bool );
        void setUFlag( bool );
        void setShootGunFlag( bool );
        void setShootSMissileFlag( bool );
        void setShootBMissileFlag( bool );
        void setShield(int theShield);
        void setsMissile(int sMissile);
        void setbMissile(int bMissile);
        void setShieldMax(int value);
        void setArmorMax(int value);
        void setShipIsDead(bool shipLife);
        void collCheck();

        int getShield();
        int getsMissile();
        int getbMissile();
        int PlayerShip::type() const;
        bool getShootGunFlag();
        bool getShootSMissileFlag();
        bool getShootBMissileFlag();
        bool isShipDead();

        enum { Type = 65536 + 2 };


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
        /*! Flag for ship shootign the gun*/
        bool shootGunFlag;
        /*! Flag for ship shooting small missiles */
        bool shootSMissileFlag;
        /*! Flag for ship shooting big missiles */
        bool shootBMissileFlag;
        /*! Max value shield is reset to. */
        int shieldMax;
        /*! Max value armor is reset to. */
        int armorMax;
        /*! Holds whether the ship is alive or dead */
        bool shipIsDead;
        /*! Holds how many advances the user ship is invincible for */
        int reset;
        void damage(int dTaken);
        void advance(int phase);
        void respawn();
        void setAllFlags(bool);
};

#endif // PLAYERSHIP_H

