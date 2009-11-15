#ifndef BASICSHIP_H
#define BASICSHIP_H\

#include <QGraphicsItem>
#include <QPainter>


class BasicShip : public QGraphicsItem
{
    public:
    BasicShip(int theArmor, int theLives, QImage theImage, int theX, int theY);
    BasicShip();
    ~BasicShip();

    int getArmor();
    int getLives();
    void setLives( int theLives );
    void setArmor(int theArmor);
    void setImage(QImage theImage);
    void setShipSizeX(int);
    void setShipSizeY(int);
    void move(qreal xMove, qreal yMove);
    enum { Type = 65536 + 1 };
    int type() const;
    int shipSizeX;
    int shipSizeY;
    void collCheck();
    void getridof();

    signals:
         void armorChanged();



    private:
        /*! The amount of armor. */
        int shipArmor;
        /*! The amount of lives. */
        int shipLives;
        /*! The imgae drawn for this ship. */
        QImage shipImage;
        int damageCounter;
        bool moveRight;
        static const qreal SCENE_WIDTH = 600;
        static const qreal SCENE_HEIGHT = 480;
        void advance(int phase);
        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


        void damage(int dTaken);
};

#endif // BASICSHIP_H


