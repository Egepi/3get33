#ifndef BASICSHIP_H
#define BASICSHIP_H\

#include <QGraphicsItem>

class BasicShip : public QGraphicsItem
{
    public:
    BasicShip(int theArmor, int theShield, int theLives);
    int getArmor();
    int getShield();
    int getLives();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget);

    private:
        int shipArmor;
        int shipShield;
        int shipLives;
};

#endif // BASICSHIP_H
