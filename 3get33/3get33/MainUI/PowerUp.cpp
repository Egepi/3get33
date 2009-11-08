#include "PowerUp.h"

// power up type 1 = sheild
// power up type 2 = health
// power up type 3 = small missile
// power up type 4 = big missile
PowerUp::PowerUp(QImage powerUpImage, int powerUpType)
{
    puType = powerUpType;
    this->setGraphicType(7);
    puImage = powerUpImage;
    puLocX = qrand() % 600;
    puLocY = qrand() % 480;
    setPos(puLocX, puLocY);
}

PowerUp::PowerUp()
{
}

PowerUp::~PowerUp()
{
}

void PowerUp::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //draws the power up to the screen
    painter->drawImage(0, 0, puImage);
}

QRectF PowerUp::boundingRect() const
{
    if(this->puType == 1 )
    {

    }
    else if(this->puType == 2 )
    {

    }
    else if(this->puType == 3 )
    {

    }
    else if(this->puType == 4 )
    {

    }
}

QPainterPath PowerUp::shape() const
{
    if(this->puType == 1 )
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }
    else if(this->puType == 2 )
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }
    else if(this->puType == 3 )
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }
    else if(this->puType == 4 )
    {
        QPainterPath path;
        path.addRect(0, 0, 20, 20);
        return path;
    }

}

int PowerUp::type() const
{
   // Enable the use of qgraphicsitem_cast with this item.
    if(this->puType == 1 )
    {
        return Type;
    }
    else if(this->puType == 2 )
    {
        return Type + 1;
    }
    else if(this->puType == 3 )
    {
        return Type + 2;
    }
    else if(this->puType == 4 )
    {
        return Type + 3;
    }
}

