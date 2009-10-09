#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BasicShip.h"
#include <QPushButton>
#include <QObject>
#include <QPixmap>
#include <QGraphicsScene>
#include "PlayerShip.h"
#include <QDialog>
#include <QFileDialog>

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

    myShip = new PlayerShip();
    myShip->setArmor(100);
    myShip->setShield(100);
    myShip->setLives(3);
    myShip->setPos(280,400);
    myShip->setImage(QImage(":/images/GoodGuy.png"));

    gameScene->addItem(myShip);


    ui->armorDisplay->display(myShip->getArmor());
    ui->sheildDisplay->display(myShip->getShield());
    ui->livesDisplay->display(myShip->getLives());

    actions.insert( Qt::Key_A, Left );
    actions.insert( Qt::Key_D, Right );
    actions.insert( Qt::Key_W, Up );
    actions.insert( Qt::Key_S, Down );
    actions.insert( Qt::Key_Space, ShootGun );
    actions.insert( Qt::Key_V, ShootSBomb );
    actions.insert( Qt::Key_B, ShootBBomb );
    actions.insert( Qt::Key_Escape, Pause );

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
    QFileDialog fileDlg;
    QStringList newFile;
    // open file dialog
    if ( fileDlg.exec() != QDialog::Accepted )
    return; // the user clicked cancel
    // get the file path
    newFile = fileDlg.selectedFiles();
    QString theFile = newFile.first();
    ui->armorLabel->setText(theFile);

}

void MainWindow::playGame()
{
}

void MainWindow::keyPressEvent(QKeyEvent *key) {

    Action a = actions[ key->key() ];
    switch(a) {
        case Left:
        myShip->setLFlag( true );
        myShip->advance();
        break;
        case Right:
        myShip->setRFlag( true );
        myShip->advance();
        break;
        case Up:
        myShip->setUFlag( true );
        myShip->advance();
        break;
        case Down:
        myShip->setDFlag( true );
        myShip->advance();
        break;
        case ShootBBomb:
        break;
        case ShootSBomb:
        break;
        case ShootGun:
        break;
        case Pause:
        break;
        default:
        cout << "key pressed " << endl << flush;
        myShip->advance();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *key) {

    Action a = actions[ key->key() ];
    switch(a) {
        case Left:
        myShip->setLFlag( false );
        myShip->advance();
        break;
        case Right:
        myShip->setRFlag( false );
        myShip->advance();
        break;
        case Up:
        myShip->setUFlag( false );
        myShip->advance();
        break;
        case Down:
        myShip->setDFlag( false );
        myShip->advance();
        break;
        case ShootBBomb:
        break;
        case ShootSBomb:
        break;
        case ShootGun:
        break;
        case Pause:
        break;
        default:
        cout << "key pressed " << endl << flush;
        myShip->advance();
    }
}
