#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BasicShip.h"
#include "PlayerShip.h"
#include <QPushButton>
#include <QObject>
#include <QPixmap>
#include <QGraphicsScene>
#include <QDialog>
#include <QFileDialog>

/**********************************************************************/
/*! Constructor for a new MainWindow in which the whole program/game is run.
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //Sets up the user interface based of mainwindow.ui

    gameScene = new QGraphicsScene; //Scene to display the whole game
    int width = ui->Display->geometry().width();
    int height = ui->Display->geometry().height();
    gameScene->setSceneRect(0, 0, width,height);
    //Sets the default background for the gameScene
    gameScene->setBackgroundBrush(QBrush(QImage(":/images/Menu.jpg")));
    ui->Display->setScene(gameScene);

    //Creates and displays the "Play", "Load Game", and "Quit" buttons
    ui->playButton->setIconSize(QSize(140,50));
    ui->playButton->setIcon(QIcon(":/images/playButton.jpg"));
    ui->playButton->setFlat(true);

    ui->quitButton->setIconSize(QSize(140,50));
    ui->quitButton->setIcon(QIcon(":/images/quitButton.jpg"));
    ui->quitButton->setFlat(true);

    ui->loadButton->setIconSize(QSize(140,50));
    ui->loadButton->setIcon(QIcon(":/images/loadButton.jpg"));
    ui->loadButton->setFlat(true);

    //connect(ui->playButton, SIGNAL(clicked()), ui->armorDisplay, SLOT(hide()));

}

/**********************************************************************/
/*! Destructor for MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**********************************************************************/
/*! Closes the program.
 *
 * Slot that is called when the 'Quit' button is clicked in the MainWindow.
 *
 *  Author: Karan Chakrapani
 */
void MainWindow::closeGame()
{
    //Closes the program.
    this->close();
}

/**********************************************************************/
/*! Prompts user to load a level file using OS generic load file ui.
  *
  * Slot is called when the 'Load Game' button is clicked from MainWindow.
  *
  * The generic OS file load window is opened and the current directory
  * from which the game is running is the default folder it opens up to.\n
  * The user loads a level file and the game will then run with the level
  * specifications.
  *
  *  Author: Karan Chakrapani,
  *          Todd Silvia
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

    //Disabled for now, because this was for testing only
    //ui->armorLabel->setText(theFile);
}

/**********************************************************************/
/*! Loads and iniates the pre-loaded game.
  *
  * A new PlayerShip is created and added to the scene.
  * The method then proceeds to up date the armor,
  * shield, and lives displays. \n
  * The pre-loaded game then is iniated.
  *
  *  Author: Karan Chakrapani
  */
void MainWindow::playGame()
{
    gameScene->setBackgroundBrush(QBrush(QImage(":/images/Background.jpg")));
    ui->loadButton->hide();
    ui->playButton->hide();
    ui->quitButton->hide();
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

    //QImage a = new QImage(":/images/BadGuy4.png");
    Enemy1 = new BasicShip(0, 0, (QImage(":/images/BadGuy4.png")), 40, 40 );
    Enemy2 = new BasicShip(0, 0, (QImage(":/images/BadGuy4.png")), 100, 100 );
}

/**********************************************************************/
/*! When ever a key is pressed this method is called to decide what action to take.
 *
 *  This method is used for key press events for moving the ship, shooting bombs,
 *  shooting guns, and pausing the game. All other keys just do nothing.
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
void MainWindow::keyPressEvent(QKeyEvent *key) {

    Action a = actions[ key->key() ];
    switch(a) {
        case Left:  //Move ship Left
        myShip->setLFlag( true );
        myShip->advance();
        break;
        case Right: //Move ship Right
        myShip->setRFlag( true );
        myShip->advance();
        break;
        case Up:    //Move ship Up
        myShip->setUFlag( true );
        myShip->advance();
        break;
        case Down:  //Move ship Down
        myShip->setDFlag( true );
        myShip->advance();
        break;
        case ShootBBomb:    //Shoot Big Bomb
        break;
        case ShootSBomb:    //Shoot Small Bomb
        break;
        case ShootGun:      //Shoot normal gun
        break;
        case Pause:         //Pause the game
        break;
        default:
        break;
    }
}

/**********************************************************************/
/*! When ever a key has been released this method decides to stop the current action.
 *
 *  This method just ends all of the actions that are initiated in
 *  MainWindow.keyPressEvent().
 *
 *  Author: Karan Chakrapani,
 *          Jennifer Kinahan
 */
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
        break;
    }
}
