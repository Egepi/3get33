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
        /*! Missile Image */
        QImage MissileImage;
        /*! Bool to determine whether or not Missile is big or small */
        bool bigMissile;
        /*! Decides whether enemy or player */
        bool owner;
        /*! Holds the score value */
        int score;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void advance(int phase);

};
#endif // MISSILE_H





