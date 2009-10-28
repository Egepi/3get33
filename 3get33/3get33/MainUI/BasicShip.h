#ifndef BASICSHIP_H
#define BASICSHIP_H\

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class BasicShip : public QGraphicsItem
{

    public:
    BasicShip(int theArmor, int theLives, QImage theImage, int theX, int theY);
    BasicShip();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget);
    int getArmor();
    void BasicShip::setLives( int theLives );
    int BasicShip::getLives();
    void setArmor(int theArmor);
    void setImage(QImage theImage);
    void move(qreal xMove, qreal yMove);
    void advance(int phase);


    private:
        /*! The amount of armor. */
        int shipArmor;
        /*! The amount of lives. */
        int shipLives;
        /*! The imgae drawn for this ship. */
        QImage shipImage;
};

#endif // BASICSHIP_H


