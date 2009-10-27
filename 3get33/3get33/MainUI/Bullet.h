#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class Bullet : public QGraphicsItem
{
    public:
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
        void setImage(QImage theImage);
        void shoot(qreal bulletXLoc, qreal bulletYLoc);

    private:
        int shipXLoc;
        int shipYLoc;
        int bulletXLoc;
        int bulletYLoc;
}


#endif // BULLET_H
