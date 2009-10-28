#include "BossShip.h"

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
BossShip::BossShip()
{
    this->setPos(250,10);
    this->setImage(QImage(":/images/BadGuy1.png"));
    moveLeft = true;
}

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
BossShip::~BossShip()
{
}

/**********************************************************************/
/*!
 *
 * Author: Todd Silvia
 */
void BossShip::advance(int phase)
{
    if(!phase) return;
    if(((this->x() - 2) >=0)&&(moveLeft == true))
    {
        this->move(-2,0);
    }
    else
    {
        moveLeft = false;
    }
    if(((this->x() + 2) <=520)&&(moveLeft == false))
    {
        this->move(2,0);
    }
    else
    {
        moveLeft = true;
    }
}

void BossShip::bossShoot()
{
    Bullet *aBullet = new Bullet(this->x(),this->y(),QImage(":/images/BlueBullet.png"), true);
    //MainWindow::gameScene->addItem(aBullet);

}
