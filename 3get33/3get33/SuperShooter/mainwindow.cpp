#include "mainwindow.h"


/**********************************************************************/
/*! Constructor for a new MainWindow in which the whole program/game is run.
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);  //Sets up the user interface based of mainwindow.ui
    atBoss = false;
	bossLife = new QProgressBar(this);
    bossLife->setVisible(false);
    score = 0;

    gameScene = new QGraphicsScene; //Scene to display the whole game
    width = ui->Display->geometry().width();
    height = ui->Display->geometry().height();
    gameScene->setSceneRect(0, 0, width,height);
    //Sets the default background for the gameScene
    ui->Display->setBackgroundBrush(QBrush(QImage(":/images/Menu.jpg")));
    //gameScene->setBackgroundBrush(QBrush(QImage(":/images/Menu.jpg")));
    ui->Display->setScene(gameScene);
    // ui->Display->setFocus();
    //ui->Display->centerOn(myShip);
    yDelta = -480;




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

    QObject::connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(checkQuit()));
    QObject::connect(ui->playButton, SIGNAL(clicked()),this, SLOT(gamelvl()));
    QSound::play(QString("EX_1.wav"));

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
    QString fileName = QFileDialog::getOpenFileName(this,
                                        tr("Open Level"), ".",
                                        tr("Level Files (*.lvl)"));

    if(!fileName.isEmpty()) //Checks if the file name is valid
    {
        //The player controled PlayerShip is created.
        myShip = new PlayerShip();
        gameScene->addItem(myShip); //Adds PlayerShip to scene
        bool ok = true;
        QFile levelFile(fileName);
        QString line;

        if(levelFile.open(QIODevice::ReadWrite))
        {
            QTextStream t(&levelFile);
            line = t.readLine();
            QStringList tokLine;
            while(!t.atEnd())
            {
                tokLine = line.split("#");
                if(tokLine.first().compare(QString("PlayerArmor")) == 0)
                {
                    myShip->setArmor(tokLine.at(1).toInt(&ok));
                    myShip->setArmorMax(tokLine.at(1).toInt(&ok));
                    ui->armorDisplay->display(myShip->getArmor());
                }
                else if(tokLine.first().compare(QString("PlayerShield")) == 0)
                {
                    myShip->setShield(tokLine.at(1).toInt(&ok));
                    myShip->setShieldMax(tokLine.at(1).toInt(&ok));
                    ui->shieldDisplay->display(myShip->getShield());
                }
                else if(tokLine.first().compare(QString("PlayerLives")) == 0)
                {
                    myShip->setLives(tokLine.at(1).toInt(&ok));
                    ui->livesDisplay->display(myShip->getLives());
                }
                else if(tokLine.first().compare(QString("PlayerBigBombs")) == 0)
                {
                    myShip->setsMissile(tokLine.at(1).toInt(&ok));
                    ui->smallMissilesDisplay->display(myShip->getsMissile());
                }
                else if(tokLine.first().compare(QString("PlayerSmallBombs")) == 0)
                {
                    myShip->setbMissile(tokLine.at(1).toInt(&ok));
                    ui->bigMissilesDisplay->display(myShip->getbMissile());
                }
                else
                {
                    line = t.readLine();
                    continue;
                }
            }
        }
        levelFile.close();
        QImage theType(":/images/BadGuy4.png");
        preLevel = new Level(gameScene, theType, 20);
        this->playGame();
    }
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
    ui->loadButton->hide();
    ui->playButton->hide();
    //Maps the keys to play the game
    actions.insert( Qt::Key_A, Left );
    actions.insert( Qt::Key_D, Right );
    actions.insert( Qt::Key_W, Up );
    actions.insert( Qt::Key_S, Down );
    actions.insert( Qt::Key_Space, ShootGun );
    actions.insert( Qt::Key_V, ShootSBomb );
    actions.insert( Qt::Key_B, ShootBBomb );
    actions.insert( Qt::Key_Escape, Pause );

    bg = new BGround();
    gameScene->addItem(bg);

    //Updates the armor, shield, and lives displays.
    ui->armorDisplay->display(myShip->getArmor());
    ui->shieldDisplay->display(myShip->getShield());
    ui->livesDisplay->display(myShip->getLives());
    ui->quitButton->clearFocus();
    gameStarted = true;
    if(gameStarted == true)
    {
        preLevel->shipAdvance();
        theWavePtr = preLevel->addWave();
        //Actual value 180000
        QTimer::singleShot(1800, this, SLOT(startBoss()));
        waveTimer = new QTimer();
        QObject::connect(waveTimer, SIGNAL(timeout()), this, SLOT(addingWave()));
        waveTimer->start(30000);
        enemyShootTimer = new QTimer();
        QObject::connect(enemyShootTimer, SIGNAL(timeout()), this, SLOT(enemyShoot()));
        enemyShootTimer->start(3000);

        gameUpdate = new QTimer;
        QObject::connect(gameUpdate,SIGNAL(timeout()), this, SLOT(updateArmor()));
        QObject::connect(gameUpdate,SIGNAL(timeout()), this, SLOT(playerShoot()));
        gameUpdate->start(1000/10);
        this->spawnPowerUp();

    }
    //this->gamelvl();



}

/**********************************************************************/
/*!
 * STUFF
 */
void MainWindow::addingWave(){
    theWavePtr = preLevel->addWave();
}
/**********************************************************************/
/*!
 *
 *  Author: Todd Silvia
 */
void MainWindow::gamelvl()
{
    //The player controled PlayerShip is created.
    myShip = new PlayerShip();
    gameScene->addItem(myShip); //Adds PlayerShip to scene

    QImage theType(":/images/BadGuy4.png");
    preLevel = new Level(gameScene, theType, 20);
    this->playGame();
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
    if(myShip->isEnabled()==false) return;
    Action a = actions[ key->key() ];
    switch(a) {
        case Left:  //Move ship Left
            myShip->setLFlag( true );
        break;
        case Right: //Move ship Right
            myShip->setRFlag( true );
        break;
        case Up:    //Move ship Up
            myShip->setUFlag( true );
        break;
        case Down:  //Move ship Down
            myShip->setDFlag( true );
        break;
        case ShootBBomb:    //Shoot Big Bomb
            myShip->setShootBMissileFlag(true);
        break;
        case ShootSBomb:    //Shoot Small Bomb
            myShip->setShootSMissileFlag(true);
        break;
        case ShootGun:      //Shoot normal gun
            myShip->setShootGunFlag(true);
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
    if(myShip->isEnabled()==false) return;
    Action a = actions[ key->key() ];
    switch(a) {
        case Left:
            myShip->setLFlag( false );
        break;
        case Right:
            myShip->setRFlag( false );
        break;
        case Up:
            myShip->setUFlag( false );
        break;
        case Down:
            myShip->setDFlag( false );
        break;
        case ShootBBomb:    //Shoot Big Bomb
            myShip->setShootBMissileFlag(false);
        break;
        case ShootSBomb:    //Shoot Small Bomb
            myShip->setShootSMissileFlag(false);
        break;
        case ShootGun:      //Shoot normal gun
            myShip->setShootGunFlag(false);
        break;
        case Pause:
        break;
        default:
        break;
    }
}

/**********************************************************************/
/*!
 *
 *  Author: Todd Silvia
 */
void MainWindow::checkQuit()
{
    switch (QMessageBox::warning(this, "Quit Program ?",
                         "Are you sure you want to quit the game?",
                         QMessageBox::No | QMessageBox::Default,
                         QMessageBox::Yes | QMessageBox::Escape)) {
    case QMessageBox::No:
            break;
    case QMessageBox::Yes:
            this->closeGame();
            break;
        }
}

/**********************************************************************/
/*!
 *
 *  Author: Todd Silvia
 */
void MainWindow::startBoss()
{
    atBoss = true;
    preLevel->startBoss();
    bossLife->setGeometry(10,230,121,23);
    bossLife->setMinimum(0);
    bossLife->setMaximum(preLevel->theBoss->getArmor());
    bossLife->setValue(preLevel->theBoss->getArmor());
    bossLife->setVisible(true);
}

/**********************************************************************/
void MainWindow::enemyShoot()
{
    if(atBoss == true && preLevel->theBoss->isEnabled() == true)
    {
        Bullet *aBullet = new Bullet(preLevel->theBoss->x()+75,preLevel->theBoss->y()+72,QImage(":/images/greenBossBullet.png"), false);
        gameScene->addItem(aBullet);
        Bullet *bBullet = new Bullet(preLevel->theBoss->x()+56,preLevel->theBoss->y()+72,QImage(":/images/greenBossBullet.png"), false);
        gameScene->addItem(bBullet);
        Bullet *cBullet = new Bullet(preLevel->theBoss->x()+94,preLevel->theBoss->y()+72,QImage(":/images/greenBossBullet.png"), false);
        gameScene->addItem(cBullet);
        Bullet *dBullet = new Bullet(preLevel->theBoss->x()+75,preLevel->theBoss->y()+92,QImage(":/images/greenBossBullet.png"), false);
        gameScene->addItem(dBullet);
        Bullet *eBullet = new Bullet(preLevel->theBoss->x()+56,preLevel->theBoss->y()+92,QImage(":/images/greenBossBullet.png"), false);
        gameScene->addItem(eBullet);
        Bullet *fBullet = new Bullet(preLevel->theBoss->x()+94,preLevel->theBoss->y()+92,QImage(":/images/greenBossBullet.png"), false);
        gameScene->addItem(fBullet);
    }
    if(!this->theWavePtr->isEmpty())
    {  //ui->armorLabel->setText("LOL");
       for( int i = 0; i <= theWavePtr->length(); i++ )
       {

       }
    }
}

/**********************************************************************/
void MainWindow::updateArmor()
{
    this->bg->setPos(0, yDelta);
    if(yDelta < 0)
    {
        yDelta += 1;
    }
    else
    {
        yDelta = -480;
    }
    ui->armorDisplay->display(myShip->getArmor());
    ui->shieldDisplay->display(myShip->getShield());
    ui->livesDisplay->display(myShip->getLives());
    ui->smallMissilesDisplay->display(myShip->getsMissile());
    ui->bigMissilesDisplay->display(myShip->getbMissile());
    score = 0;
    if(!this->bulletList.isEmpty())
    {
       QLinkedList<Bullet*>::iterator iterator;
       for(iterator = bulletList.begin(); iterator != bulletList.end(); ++iterator)
       {
           Bullet *a = *iterator;
           score = score + a->getScore();
       }
    }
    if(!this->missileList.isEmpty())
    {
       QLinkedList<Missile*>::iterator iterator2;
       for(iterator2 = missileList.begin(); iterator2 != missileList.end(); ++iterator2)
       {
           Missile *b = *iterator2;
           score = score + b->getScore();
       }
    }
    ui->scoreDisplay->display(score);
    if(atBoss == true)
        bossLife->setValue(preLevel->theBoss->getArmor());

    if(myShip->isShipDead())
    {
        gameUpdate->stop();
        gameScene->removeItem(bg);
    }
    if((atBoss == true)&&(!(preLevel->theBoss->isEnabled())))
    {
        ui->scoreDisplay->display(9999);
    }


}
/**********************************************************************/
void MainWindow::makePowerUp()
{
    PowerUp *aPU = new PowerUp();
    gameScene->addItem(aPU);
}

/**********************************************************************/
void MainWindow::spawnPowerUp()
{
    QTimer *powerUpTimer = new QTimer();
    QObject::connect(powerUpTimer, SIGNAL(timeout()), this, SLOT(makePowerUp()));
    powerUpTimer->start(20000);
}

/**********************************************************************/
void MainWindow::playerShoot()
{
    if(myShip->getShootGunFlag())
    {
        Bullet *aBullet = new Bullet(myShip->x()+36,myShip->y()-9,QImage(":/images/WhiteBullet.png"), true);
        gameScene->addItem(aBullet);
        QSound::play(QString("pew2.wav"));
        this->bulletList.append(aBullet);
    }

    if(myShip->getShootSMissileFlag())
    {
        if(myShip->getsMissile() > 0)
        {
            Missile *aSmallMissile = new Missile(myShip->x()+35, myShip->y()-21,QImage(":/images/sMissile.png"), true, false);
            gameScene->addItem(aSmallMissile);
            myShip->setsMissile(myShip->getsMissile() -1);
             QSound::play(QString("missileShot.wav"));
            this->missileList.append(aSmallMissile);
        }

    }

    if(myShip->getShootBMissileFlag())
    {
        if(myShip->getbMissile() > 0)
        {
            Missile *aBigMissile = new Missile(myShip->x()+30, myShip->y()-41,QImage(":/images/bMissile.png"), true, true);
            gameScene->addItem(aBigMissile);
            myShip->setbMissile(myShip->getbMissile() -1);
             QSound::play(QString("missileshot.wav"));
            this->missileList.append(aBigMissile);
        }
    }
}
