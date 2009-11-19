#include "bground.h"

BGround::BGround()
{
    this->setZValue(5);
}

BGround::~BGround()
{
}


QRectF BGround::boundingRect() const
{
    return QRectF(0,0,600,480);
}


QPainterPath BGround::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 600,480);
    return path;
}

void BGround::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

        //Draws the BGround object.
        painter->drawImage(0,0, QImage(":/images/LargeBG.png"));
}
