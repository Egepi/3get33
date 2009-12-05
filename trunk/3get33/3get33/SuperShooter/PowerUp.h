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
        /*! Power Up Image */
        QImage puImage;
        /*! Holds value between 1 and 4 for the type of power up it is */
        int puType;
        /*! Holds a random x value for the power up*/
        int puLocX;
        /*! Holds a random y value for the power up */
        int puLocY;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void advance(int);
};

#endif // POWERUP_H
