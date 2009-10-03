#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BasicShip.h"
#include <QPushButton>
#include <QObject>
#include <QPixmap>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QGraphicsScene *gameScene = new QGraphicsScene;
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
    BasicShip *myShip = new BasicShip();
    myShip->setArmor(100);
    myShip->setShield(100);
    myShip->setLives(3);
    myShip->setLoc(280,400);
    myShip->setImage(QImage(":/images/GoodGuy.png"));



    gameScene->addItem(myShip);


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
