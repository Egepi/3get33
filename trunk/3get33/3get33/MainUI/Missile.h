#ifndef MISSILE_H
#define MISSILE_H

#include <QGraphicsItem>
#include <QPainter>

class Missile : public QGraphicsItem
{
public:
        Missile();
        Missile(qreal locX, qreal locY, QImage missImage, bool owner, bool big);
        ~Missile();
        enum {Type = 65536 + 5};
        int Missile::type() const;

    private:
        QImage MissileImage;
        bool bigMissile;
        bool owner;

        void Missile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF Missile::boundingRect() const;
        QPainterPath Missile::shape() const;
        void Missile::advance(int phase);

};
#endif // MISSILE_H





