#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BasicShip.h"
#include <QPushButton>
#include <QObject>
#include <QPixmap>
#include <QGraphicsScene>
#include "PlayerShip.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    MyScene *gameScene = new MyScene;
    int width = ui->Display->geometry().width();
    int height = ui->Display->geometry().height();
    gameScene->setSceneRect(0, 0, width,height);
    gameScene->setBackgroundBrush(QBrush(QImage(":/images/Menu.jpg")));
    ui->Display->setScene(gameScene);

    ui->playButton->setIconSize(QSize(140,50));
    ui->playButton->setIcon(QIcon(":/images/playButton.jpg"));
    ui->playButton->setFlat(true);

    ui->quitButton->setIconSize(QSize(140,50));
    ui->quitButton->setIcon(QIcon(":/images/quitButton.jpg"));
    ui->quitButton->setFlat(true);

    ui->loadButton->setIconSize(QSize(140,50));
    ui->loadButton->setIcon(QIcon(":/images/loadButton.jpg"));
    ui->loadButton->setFlat(true);

    //BasicShip myShip(100,100,3, QImage(":/images/GoodGuy.jpg"));

    PlayerShip *myShip = new PlayerShip();
    myShip->setArmor(100);
    myShip->setShield(100);
    myShip->setLives(3);
    myShip->setPos(280,400);
    myShip->setImage(QImage(":/images/GoodGuy.png"));

    BasicShip *bad1 = new BasicShip();
    bad1->setPos(0,0);
    bad1->setImage(QImage(":/images/BadGuy1.png"));

    BasicShip *bad2 = new BasicShip();
    bad2->setPos(80,0);
    bad2->setImage(QImage(":/images/BadGuy2.png"));

    BasicShip *bad3 = new BasicShip();
    bad3->setPos(160,0);
    bad3->setImage(QImage(":/images/BadGuy3.png"));

    BasicShip *bad4 = new BasicShip();
    bad4->setPos(240,0);
    bad4->setImage(QImage(":/images/BadGuy4.png"));

    gameScene->addItem(myShip);
    gameScene->addItem(bad1);
    gameScene->addItem(bad2);
    gameScene->addItem(bad3);
    gameScene->addItem(bad4);



    ui->armorDisplay->display(myShip->getArmor());
    ui->sheildDisplay->display(myShip->getShield());
    ui->livesDisplay->display(myShip->getLives());

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************
 * This SLOT is called when the quitButton is clicked
 */
void MainWindow::closeGame()
{
    this->close();
}
void MainWindow::loadGame()
{

}
void MainWindow::playGame()
{
}
