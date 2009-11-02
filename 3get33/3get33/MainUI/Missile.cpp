#include "Missile.h"

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

Missile::Missile(bool a)
{
    big = a;
}


QRectF Missile::boundingRect(bool big) const
{
    if (this->big == false)
    {
        return QRectF(0,0,20,20);
    }
    else if(this->big == true)
    {
        return QRectF(0,0,40,40);
    }
}

QPainterPath Missile::shape(bool big) const
{
    if (this->big == false)
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }
    else if (this->big == true)
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }
}
QPainterPath Missile::shape() const
{
}

