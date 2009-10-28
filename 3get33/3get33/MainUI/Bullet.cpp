#include "Bullet.h"

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

Bullet::Bullet()
{
}

Bullet::Bullet(qreal shipX, qreal shipY, QImage bullImage, bool owner)
{

    setPos(shipX+36, shipY-5);
    bulletImage = bullImage;
}

Bullet::~Bullet()
{
    delete this;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //draws the bullet to the screen
    painter->drawImage(0,0, bulletImage);
}

void Bullet::setBulletImage(QImage theBulletImage)
{
    Bullet::bulletImage = theBulletImage;
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,8,8);
}

QPainterPath Bullet::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 8, 8);
    return path;
}


//void Bullet::shoot()
//{

//}
