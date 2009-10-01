#ifndef BASICSHIP_H
#define BASICSHIP_H\

#include <QGraphicsItem>

class BasicShip : public QGraphicsItem
{
    public:
    BasicShip(int theArmor, int theShield, int theLives);
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

    private:
        int shipArmor;
        int shipShield;
        int shipLives;
};

#endif // BASICSHIP_H
