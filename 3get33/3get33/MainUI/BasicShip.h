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
    BasicShip(int theArmor, int theShield, int theLives, QImage theImage);
    BasicShip();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget);

    int getArmor();
    int getShield();
    int getLives();
    void setArmor(int theArmor);
    void setShield(int theShield);
    void setLives(int theLives);
    void setLoc(int x, int y);
    void setImage(QImage theImage);
    QImage shipImage;

    private:
        int shipArmor;
        int shipShield;
        int shipLives;
        int xLoc;
        int yLoc;

};

#endif // BASICSHIP_H
