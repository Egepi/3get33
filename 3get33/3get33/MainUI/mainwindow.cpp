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

    // pb_PlayGame->show();

    BasicShip myShip(100,100,3);
    ui->armorDisplay->display(myShip.getArmor());
    ui->sheildDisplay->display(myShip.getShield());
    ui->livesDisplay->display(myShip.getLives());

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
