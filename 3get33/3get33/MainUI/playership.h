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
    int PlayerShip::getLives();
    void PlayerShip::setLives(int theLives);
private:
    int shipLives;
    int sBombs;
    int bBombs;
    int gunType;
    bool lFlag;
    bool rFlag;
    bool dFlag;
    bool uFlag;

};

#endif // PLAYERSHIP_H
