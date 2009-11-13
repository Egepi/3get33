#ifndef BULLET_H
#define BULLET_H

#include <QPainter>
#include <QGraphicsItem>


class Bullet : public QGraphicsItem
{
    public:
        Bullet();
        Bullet(qreal locX, qreal locY, QImage bulletImage, bool owner);
        ~Bullet();       
        enum { Type = 65536 + 4 };
        int Bullet::type() const;

    private:
        qreal shipX;
        qreal shipY;
        QImage bulletImage;
        bool owner;

        void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF Bullet::boundingRect() const;
        QPainterPath Bullet::shape() const;
        void Bullet::advance(int phase);
};

#endif // BULLET_H
