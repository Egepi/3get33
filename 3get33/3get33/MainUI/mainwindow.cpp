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

    gameScene = new QGraphicsScene;
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

}

/*! This is the destructor for MainWindow Class.
  */
MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************/
/*! This slot is called when the 'Quit' button is
  * pressed in the Main Window.
 */
void MainWindow::closeGame()
{
    //Closes the program.
    this->close();
}

/**************************************************/
/*! This slot is called when the 'Load Game' button is
  * clicked.
  *
  * The generic OS file load window is opened and the
  * current directory from which the game is running
  * is the default folder it opens up to.\n
  * The user loads a level file and the game will then
  * run with the level specifications.
  */
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

/**************************************************/
/*! Loads and iniates the pre-loaded game.
  *
  * A new PlayerShip is created and added to the scene.
  * The method then proceeds to up date the armor,
  * shield, and lives displays. \n
  * The pre-loaded game then is iniated.
  */
void MainWindow::playGame()
{
    //Maps the keys to play the game
    actions.insert( Qt::Key_A, Left );
    actions.insert( Qt::Key_D, Right );
    actions.insert( Qt::Key_W, Up );
    actions.insert( Qt::Key_S, Down );
    actions.insert( Qt::Key_Space, ShootGun );
    actions.insert( Qt::Key_V, ShootSBomb );
    actions.insert( Qt::Key_B, ShootBBomb );
    actions.insert( Qt::Key_Escape, Pause );

    //The player controled PlayerShip is created.
    myShip = new PlayerShip();
    gameScene->addItem(myShip); //Adds PlayerShip to scene

    //Updates the armor, shield, and lives displays.
    ui->armorDisplay->display(myShip->getArmor());
    ui->sheildDisplay->display(myShip->getShield());
    ui->livesDisplay->display(myShip->getLives());
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
        break;
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
