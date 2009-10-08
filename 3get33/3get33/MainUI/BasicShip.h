#ifndef BASICSHIP_H
#define BASICSHIP_H\

#include <QGraphicsItem>
#include <iostream>
#include <QPixmap>
#include <QPainter>

using namespace std;

class BasicShip : public QGraphicsItem
{
    public:
    BasicShip(int theArmor, int theShield, qreal theX, qreal theY);
    BasicShip();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget);

    int getArmor();
    int getShield();

    void setArmor(int theArmor);
    void setShield(int theShield);
    void setImage(QImage theImage);
    void move(qreal xMove, qreal yMove);


    private:
        int shipArmor;
        int shipShield;

        int xLoc;
        int yLoc;
        QImage shipImage;
};

#endif // BASICSHIP_H
