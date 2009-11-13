#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsItem>
#include <QPainter>


class PowerUp : public QGraphicsItem
{
    public:
        PowerUp::PowerUp();
        PowerUp::~PowerUp();
        enum {Type = 65536 + 7};
        int PowerUp::type() const;

    private:
        QImage puImage;
        int puType;
        int puLocX;
        int puLocY;

        void PowerUp::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF PowerUp::boundingRect() const;
        QPainterPath PowerUp::shape() const;
};

#endif // POWERUP_H
