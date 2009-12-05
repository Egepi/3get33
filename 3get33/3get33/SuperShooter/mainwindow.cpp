/** File: MainWindow.cpp
  * Header: mainwindow.h
  * Author: 3get33 - Jennifer Kinahan, Karan Chakrapani, Todd Silvia
  * Last Modified: December 4th 2009
  * Purpose: This class is the main class for the entire SuperShooter game.
  *          Handles everything with the user interface, and user interaction,
  *          including all of the buttons, and key bindings. Also controls all
  *          of the gameplay.
  */
#include "mainwindow.h"


/**********************************************************************/
/*! Constructor for a new MainWindow in which the whole program/game is run.
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{   //Sets up the user interface based of mainwindow.ui
    ui->setupUi(this);
    atBoss = false; //The level is not at the boss
    bossLife = new QProgressBar(this); //Creates the boss progress bar
    bossLife->setVisible(false);       //Sets the prgress bar to invisible
    ui->bossLifeLabel->setVisible(false);   //Sets label to invisible
    score = 0;  //Sets beginning score to zero

    gameScene = new QGraphicsScene; //Scene to display the whole game
    width = ui->Display->geometry().width();    //Loads gameScene width
    height = ui->Display->geometry().height();  //Loads gameScene height
    gameScene->setSceneRect(0, 0, width,height);//Sets height and width of gameScene
    //Sets the default background for the gameScene
    ui->Display->setBackgroundBrush(QBrush(QImage(":/images/Menu.jpg")));
    ui->Display->setScene(gameScene);
    yDelta = -480;  //Calculates where the top of the background is compared to (0,0)
    alternate = false;  //Change which enemy ships in the wave are firing.



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
    ui->loadButton->setEnabled(false);

    QObject::connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(checkQuit()));
    QObject::connect(ui->playButton, SIGNAL(clicked()),this, SLOT(gamelvl()));

    QSound::play(QString("MenuBGM.wav"));   //Plays menu music.
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
  * NOTE: THIS METHOD IS NOT FULLY FUNCTIONAL YET, AND WAS ABANDONED FOR FINAL RELEASE
  *
  *  Author: Karan Chakrapani,
  *          Todd Silvia
  */
void MainWindow::loadGame()
{
    //Opens a new OS generic load file window, with *.lvl filter
    QString fileName = QFileDialog::getOpenFileName(this,
                                        tr("Open Level"), ".",
                                        tr("Level Files (*.lvl)"));

    if(!fileName.isEmpty()) //Checks if the file name is valid
    {
        //The player controled PlayerShip is created.
        myShip = new PlayerShip();
        gameScene->addItem(myShip); //Adds PlayerShip to scene
        bool ok = true; //Used to convert from QString to integer
        QFile levelFile(fileName);  //Initializes the file to be read
        QString line;

        //Open the file if it is a Readable and Writeable file
        if(levelFile.open(QIODevice::ReadWrite))
        {
            QTextStream t(&levelFile);  //Create a QTextStream to read in from the file
            line = t.readLine();        //Read in the first line from the file
            QStringList tokLine;        //Creates a string tokenizer
            //Loop while the file has another line to read from
            while(!t.atEnd())
            {
                tokLine = line.split("#");  //Split the line at each '#' char
                if(tokLine.first().compare(QString("PlayerArmor")) == 0)
                {//Set the defualt armor value of myShip if specified in the file
                    myShip->setArmor(tokLine.at(1).toInt(&ok));
                    myShip->setArmorMax(tokLine.at(1).toInt(&ok));
                    ui->armorDisplay->display(myShip->getArmor());
                }
                else if(tokLine.first().compare(QString("PlayerShield")) == 0)
                {//Set default shield value of myShip if specified in the file
                    myShip->setShield(tokLine.at(1).toInt(&ok));
                    myShip->setShieldMax(tokLine.at(1).toInt(&ok));
                    ui->shieldDisplay->display(myShip->getShield());
                }
                else if(tokLine.first().compare(QString("PlayerLives")) == 0)
                {//Set default number of lives value of myShip if specified in the file
                    myShip->setLives(tokLine.at(1).toInt(&ok));
                    ui->livesDisplay->display(myShip->getLives());
                }
                else if(tokLine.first().compare(QString("PlayerBigBombs")) == 0)
                {//Set default number of big missiles of myShip if specified in the file.
                    myShip->setsMissile(tokLine.at(1).toInt(&ok));
                    ui->smallMissilesDisplay->display(myShip->getsMissile());
                }
                else if(tokLine.first().compare(QString("PlayerSmallBombs")) == 0)
                {//Set default number of small missiles of myShip if specified in the file.
                    myShip->setbMissile(tokLine.at(1).toInt(&ok));
                    ui->bigMissilesDisplay->display(myShip->getbMissile());
                }
                else
                {//This line of the file was none of the above so load next line in file.
                    line = t.readLine();
                    continue;
                }
            }
        }
        levelFile.close();  //Close the level file
        QImage theType(":/images/BadGuy4.png"); //Set default picture of enemy ships
        preLevel = new Level(gameScene, theType, 20);   //Creates a new level object for the game
        this->playGame();   //Begin SuperShooter level implementation.
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
  *  Author: Karan Chakrapani,
  *          Todd Silvia
  */
void MainWindow::playGame()
{
    //Hides both load and play button
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

    bg = new BGround();     //Create scrolling background object
    gameScene->addItem(bg); //Add scrolling background to the scene

    //Updates the armor, shield, and lives displays.
    ui->armorDisplay->display(myShip->getArmor());
    ui->shieldDisplay->display(myShip->getShield());
    ui->livesDisplay->display(myShip->getLives());
    ui->quitButton->clearFocus();
    gameStarted = true;

    if(gameStarted == true)
    {
        //Move the ships on the screen
        preLevel->shipAdvance();
        //Add a enemy wave to the screen
        theWavePtr = preLevel->addWave();
        //Actual value 180000, sets time to load the boss at.
        QTimer::singleShot(180000, this, SLOT(startBoss()));
        waveTimer = new QTimer();   //Timer to determine how often a new wave is created
        QObject::connect(waveTimer, SIGNAL(timeout()), this, SLOT(addingWave()));
        waveTimer->start(30000);
        enemyShootTimer = new QTimer(); //Timer to determine how fast the enimes shoot
        QObject::connect(enemyShootTimer, SIGNAL(timeout()), this, SLOT(enemyShoot()));
        enemyShootTimer->start(3000);

        gameUpdate = new QTimer;    //Timer to determine the pace of the game updating
        QObject::connect(gameUpdate,SIGNAL(timeout()), this, SLOT(updateDisplay()));
        QObject::connect(gameUpdate,SIGNAL(timeout()), this, SLOT(playerShoot()));
        gameUpdate->start(1000/10);
        this->spawnPowerUp();   //Begin the spawing of powerups
    }
}

/**********************************************************************/
/*! Slot to add a wave of enemy ships to the scene
 *
 * Author: Karan Chakrapani
 */
void MainWindow::addingWave()
{
    theWavePtr = preLevel->addWave();
}

/**********************************************************************/
/*! Is called when the 'PlayGame' button is pressed to load default level.
 *
 *  Author: Todd Silvia
 */
void MainWindow::gamelvl()
{
    //The player controled PlayerShip is created.
    myShip = new PlayerShip();
    gameScene->addItem(myShip); //Adds PlayerShip to scene

    QImage theType(":/images/BadGuy4.png"); //Loads default image for enemy ships
    preLevel = new Level(gameScene, theType, 20);   //Creates a new level object for the SuperShooter level
    this->playGame();   //Go to the rest of the game play implementation
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
/*! Slot that is called when the user clicks on the 'Quit' button.
 *
 * Asks user via a message box if they want to exit the game or continue.
 *
 * Author: Todd Silvia
 */
void MainWindow::checkQuit()
{
    //Displays a message box asking user if they would like to quit the game.
    switch (QMessageBox::warning(this, "Quit Program ?",
                         "Are you sure you want to quit the game?",
                         QMessageBox::No | QMessageBox::Default,
                         QMessageBox::Yes | QMessageBox::Escape)) {
    case QMessageBox::No:
            break; //User clicked the 'No' button
    case QMessageBox::Yes:
            this->closeGame(); //User clicked the 'Yes' button
            break;
        }
}

/**********************************************************************/
/*! Loads the boss on the scene, and the progress bar for boss life.
 *
 *  Author: Todd Silvia
 */
void MainWindow::startBoss()
{
    atBoss = true;
    preLevel->startBoss();
    //Sets up boss life progress bar, and displays it
    bossLife->setGeometry(10,230,150,23);
    bossLife->setMinimum(0);
    bossLife->setMaximum(preLevel->theBoss->getArmor());
    bossLife->setValue(preLevel->theBoss->getArmor());
    bossLife->setVisible(true);
    ui->bossLifeLabel->setVisible(true);
    //Stops timer, so that no more enemy waves are added after the boss is out
    waveTimer->stop();
}

/**********************************************************************/
/*! KARAN DO THIS
  *
  *
  */
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
if(alternate)
    {
        alternate = false;
    }
    else
    {
        alternate = true;
    }
    if(!this->theWavePtr->isEmpty())
    {
       for( int i = 0; i < theWavePtr->length(); i=i+2 )
       {
           if(alternate)
           {
               BasicShip *waveShip = theWavePtr->at(i);
               if(waveShip->isEnabled())
               {
                   Bullet *gBullet = new Bullet(waveShip->x()+36,waveShip->y()+89,QImage(":/images/BlueBullet.png"), false);
                   gameScene->addItem(gBullet);
               }
           }
           else
           {
               BasicShip *waveShip = theWavePtr->at(i+1);
               if(waveShip->isEnabled())
               {
                   Bullet *gBullet = new Bullet(waveShip->x()+36,waveShip->y()+89,QImage(":/images/BlueBullet.png"), false);
                   gameScene->addItem(gBullet);
               }
           }
       }
    }
}

/**********************************************************************/
/*! KARAN FINSISH
  *
  *
  * Author: Todd Silvia,
  *         Karan Chakrapani
  */
void MainWindow::updateDisplay()
{
    this->bg->setPos(0, yDelta);    //Move the scrolling background
    if(yDelta < 0)
    {
        yDelta += 1;                //Set yDelta for next method call
    }
    else
    {
        yDelta = -480;              //Background has reached the end, reset position.
    }
    //Upate the LCD displays for the PlayerShip
    ui->armorDisplay->display(myShip->getArmor());
    ui->shieldDisplay->display(myShip->getShield());
    ui->livesDisplay->display(myShip->getLives());
    ui->smallMissilesDisplay->display(myShip->getsMissile());
    ui->bigMissilesDisplay->display(myShip->getbMissile());

    score = 0;  //Reset the score to zero for recalculation

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

    //Checks if the boss is on the screen, if so then update the boss life progress bar
    if(atBoss == true)
        bossLife->setValue(preLevel->theBoss->getArmor());

    //Checks if the ship still has more lives or not
    if(myShip->isShipDead())
    {//The ship has zero lives so the game needs to be stopped.
        //Stop the timers controling the game play
        gameUpdate->stop();
        waveTimer->stop();
        enemyShootTimer->stop();
        preLevel->advanceTimer->stop();
        powerUpTimer->stop();

        //Remove the scrolling background
        gameScene->removeItem(bg);
        //Change the background to game over screen
        ui->Display->setBackgroundBrush(QBrush(QImage(":/images/MGS_GameOver.jpg")));
        //Play game over sound.
        QSound::play(QString("GameOver.wav"));
    }

    //Checks if the level is currently at the boss, and he is still alive.
    if((atBoss == true)&&(!(preLevel->theBoss->isEnabled())))
    {//The boss was out, and is now dead
        //Stop the timers controling the game play
        gameUpdate->stop();
        waveTimer->stop();
        enemyShootTimer->stop();
        preLevel->advanceTimer->stop();
        powerUpTimer->stop();

        //Remove the scrolling background
        gameScene->removeItem(bg);
        //Change background picture to the player won screen
        ui->Display->setBackgroundBrush(QBrush(QImage(":/images/youwon.gif")));
        //Update the boss life progress bar one last time.
        bossLife->setValue(preLevel->theBoss->getArmor());
    }
}

/**********************************************************************/
/*! Slot to create a powerup and places it on the screen.
  *
  * Author: Jennifer Kinahan
  */
void MainWindow::makePowerUp()
{
    //Creates new powerup object
    PowerUp *aPU = new PowerUp();
    //Adds new power up to the game scene.
    gameScene->addItem(aPU);
}

/**********************************************************************/
/*! Runs on a timer, to create power ups on the screen. Calls makePowerUp()
  *
  * Author: Jennifer Kinahan
  *
  */
void MainWindow::spawnPowerUp()
{
    //Creates a new QTimer
    powerUpTimer = new QTimer();
    //Connects timer to makePowerUp() slot
    QObject::connect(powerUpTimer, SIGNAL(timeout()), this, SLOT(makePowerUp()));
    //Sets interval for timer
    powerUpTimer->start(20000);
}

/**********************************************************************/
/*! KARAN DO THIS
  *
  * Author: Karan Chakrapani,
  *         Jennifer Kinahan
  */
void MainWindow::playerShoot()
{
    if(myShip->getShootGunFlag())
    {
        Bullet *aBullet = new Bullet(myShip->x()+36,myShip->y()-9,QImage(":/images/WhiteBullet.png"), true);
        gameScene->addItem(aBullet);
        QSound::play(QString("pew.wav"));
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
            QSound::play(QString("missileShot.wav"));
            this->missileList.append(aBigMissile);
        }
    }
}
