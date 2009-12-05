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
        bool getOwner();
        void updateScore(int);
        int getScore();

    private:
        /*! Holds the x loc of the ship */
        qreal shipX;
        /*! Holds the y loc of the ship */
        qreal shipY;
        /*! Holds the bullet image */
        QImage bulletImage;
        /*! Bool value that decides whether it's an enemy or player ship */
        bool owner;
        /*! Holds the score value */
        int score;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void advance(int phase);
};

#endif // BULLET_H
