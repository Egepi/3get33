#ifndef POWERUP_H
#define POWERUP_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTime>
#include "myGraphics.h"

class PowerUp : public myGraphics
{
    public:
        PowerUp::PowerUp();
        PowerUp::~PowerUp();
        void PowerUp::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        void PowerUp::setPowerUpImage(QImage thePowerUpImage);
        QRectF PowerUp::boundingRect() const;
        QPainterPath PowerUp::shape() const;
        enum {Type = 65536 + 7};
        int PowerUp::type() const;

    private:
        int puType;
        QImage puImage;
        int puLocX;
        int puLocY;
};

#endif // POWERUP_H
