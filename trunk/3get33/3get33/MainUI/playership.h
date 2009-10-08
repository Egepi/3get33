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
private:
};

#endif // PLAYERSHIP_H
