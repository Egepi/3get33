#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsItem>
#include <QPainter>


class PowerUp : public QGraphicsItem
{
    public:
        PowerUp();
        ~PowerUp();
        enum {Type = 65536 + 7};
        int type() const;

    private:
        QImage puImage;
        int puType;
        int puLocX;
        int puLocY;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF boundingRect() const;
        QPainterPath shape() const;
};

#endif // POWERUP_H
