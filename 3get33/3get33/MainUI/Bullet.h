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
        int type() const;

    private:
        qreal shipX;
        qreal shipY;
        QImage bulletImage;
        bool owner;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void advance(int phase);
};

#endif // BULLET_H
