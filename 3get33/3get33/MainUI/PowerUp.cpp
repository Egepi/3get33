#include "PowerUp.h"

// power up type 1 = sheild
// power up type 2 = health
// power up type 3 = small missile
// power up type 4 = big missile
PowerUp::PowerUp()
{
    puType = (qrand() % 4) +1;
    this->setGraphicType(7);
    puLocX = qrand() % 560;
    puLocY = qrand() % 440;
    setPos(puLocX, puLocY);
    //sheild
    if(this->puType == 1 )
    {
        puImage = QImage(":/images/shieldpowerup.gif");
    }
    //armor
    else if(this->puType == 2 )
    {
        puImage = QImage(":/images/greenBossBullet.png");
    }
    //smissile
    else if(this->puType == 3 )
    {
        puImage = QImage(":/images/purpleDS.png");
    }
    //bmissile
    else if(this->puType == 4 )
    {
        puImage = QImage(":/images/greenDM.png");
    }
    //sheild if nothin
    else
    {
        puImage = QImage(":/images/shieldpowerup.gif");
    }
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
        return QRectF(0,0,20,20);
    }
    else if(this->puType == 2 )
    {
        return QRectF(0,0,20,20);
    }
    else if(this->puType == 3 )
    {
        return QRectF(0,0,15,38);
    }
    else if(this->puType == 4 )
    {
        return QRectF(0,0,15,38);
    }
    else
    {
        return QRectF(0,0,20,20);
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
        path.addRect(0, 0, 15, 38);
        return path;
    }
    else if(this->puType == 4 )
    {
        QPainterPath path;
        path.addRect(0, 0, 15, 38);
        return path;
    }
    else
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
    else
    {
        return Type;
    }
}

