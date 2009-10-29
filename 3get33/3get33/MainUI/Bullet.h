#ifndef BULLET_H
#define BULLET_H

#include "myGraphics.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <QWidget>
#include <QStyleOptionGraphicsItem>

class Bullet : public myGraphics
{
    public:
        Bullet();
        Bullet(qreal shipX, qreal shipY, QImage bulletImage, bool owner);
        ~Bullet();
        void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        void Bullet::setBulletImage(QImage theBulletImage);
        //void Bullet::shoot();
        QRectF Bullet::boundingRect() const;
        QPainterPath Bullet::shape() const;
        void Bullet::advance(int phase);
        enum { Type = 65536 + 4 };
        int Bullet::type() const;

    private:
        qreal shipX;
        qreal shipY;
        int bulletX;
        int bulletY;
        QImage bulletImage;
        bool owner;
        int phase;
        int xLoc;
        int xMove;
        int yLoc;
        int yMove;
        //QGraphicsItem parent;
};

#endif // BULLET_H
