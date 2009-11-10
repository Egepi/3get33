#ifndef MISSILE_H
#define MISSILE_H

#include <QWidget>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include "myGraphics.h"

class Missile : public QGraphicsItem
{
public:
        Missile();
        Missile(qreal shipX, qreal shipY, QImage missImage, bool owner, bool big);
        ~Missile();
        void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        void Missile::setMissileImage(QImage theMissileImage);
        QRectF Missile::boundingRect() const;
        QPainterPath Missile::shape() const;
        void Missile::advance(int phase);
        enum {Type = 65536 + 5};
        int Missile::type() const;

    private:
        qreal shipX;
        qreal shipY;
        int MissileX;
        int MissileY;
        QImage MissileImage;
        bool bigMissile;
        bool owner;
        int phase;
        int xLoc;
        int xMove;
        int yLoc;
        int yMove;
};
#endif // MISSILE_H





