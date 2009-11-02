#ifndef MISSILE_H
#define MISSILE_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include "Bullet.h"

class Missile : public Bullet
{
    public:
        Missile::Missile(bool a);
        QRectF Missile::boundingRect(bool big) const;
        QPainterPath Missile::shape(bool big) const;
        QPainterPath Missile::shape() const;

    private:
        bool big;

};
#endif // MISSILE_H
