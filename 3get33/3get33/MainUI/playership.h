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
    void PlayerShip::advanceLeft();
    void PlayerShip::advanceRight();
    void PlayerShip::advanceUp();
    void PlayerShip::advanceDown();
    int getLives();
    void setLives(int theLives);
private:
    int shipLives;
    int sBombs;
    int bBombs;
    int gunType;
};

#endif // PLAYERSHIP_H
