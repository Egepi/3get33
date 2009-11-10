#ifndef BASICSHIP_H
#define BASICSHIP_H\

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include "Bullet.h"

class BasicShip : public QGraphicsItem
{
    public:
    BasicShip(int theArmor, int theLives, QImage theImage, int theX, int theY);
    BasicShip();
    ~BasicShip();
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
    int shipSizeX;
    int shipSizeY;
    enum { Type = 65536 + 1 };
    int BasicShip::type() const;
    static const qreal SCENE_WIDTH = 600;
    static const int SHIP_SIZE = 80;
    static const qreal SCENE_HEIGHT = 480;
    void BasicShip::collCheck();
    void BasicShip::damage(int dTaken);

    signals:
         void armorChanged();

    public slots:
        void getridof();

    private:
        /*! The amount of armor. */
        int shipArmor;
        /*! The amount of lives. */
        int shipLives;
        /*! The imgae drawn for this ship. */
        QImage shipImage;
        int damageCounter;
        bool moveRight;
};

#endif // BASICSHIP_H


