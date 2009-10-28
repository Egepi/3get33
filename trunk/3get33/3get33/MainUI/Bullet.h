#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <QWidget>
#include <QStyleOptionGraphicsItem>

class Bullet : public QGraphicsItem
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

    private:
        qreal shipX;
        qreal shipY;
        int bulletX;
        int bulletY;
        QImage bulletImage;
        bool owner;
        //QGraphicsItem parent;
};

#endif // BULLET_H
