#ifndef BGROUND_H
#define BGROUND_H

#include <QGraphicsItem>
#include <QPainter>


class BGround : public QGraphicsItem
{
    public:
    BGround();
    ~BGround();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BGROUND_H
