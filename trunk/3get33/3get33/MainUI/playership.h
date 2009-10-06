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
    void PlayerShip::keyPressEvent(QKeyEvent*);
    void PlayerShip::advanceLeft();
    void PlayerShip::advanceRight();
    void PlayerShip::advanceUp();
    void PlayerShip::advanceDown();
private:
    QKeyEvent *key;
};

#endif // PLAYERSHIP_H
