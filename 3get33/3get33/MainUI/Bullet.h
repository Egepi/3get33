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
        Bullet(int shipX, int shipY);
        ~Bullet();
        void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        void Bullet::setBulletImage(QImage theBulletImage);
        //void Bullet::shoot();

    private:
        int shipX;
        int shipY;
        int bulletX;
        int bulletY;
        QImage bulletImage;
        //QGraphicsItem parent;
};

#endif // BULLET_H
