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
        int type() const;
        bool getOwner();
        void updateScore(int);
        int getScore();

    private:
        QImage MissileImage;
        bool bigMissile;
        bool owner;
        int score;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void advance(int phase);

};
#endif // MISSILE_H





