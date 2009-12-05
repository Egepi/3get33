#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "BasicShip.h"
#include "PlayerShip.h"
#include "Level.h"
#include "Bullet.h"
#include "Missile.h"
#include "PowerUp.h"
#include "BasicShip.h"
#include "PlayerShip.h"
#include "Level.h"
#include "bground.h"
#include "ui_mainwindow.h"

#include <QtGui/QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QPixmap>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QSound>
#include <QDialog>
#include <QFileDialog>
#include <QLinkedList>
#include <QProgressBar>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void closeGame();
    void loadGame();
    void playGame();
    void checkQuit();
    void startBoss();
    void enemyShoot();
    void updateDisplay();
    void makePowerUp();
    void playerShoot();
    void gamelvl();
    void addingWave();

private:
    Ui::MainWindow *ui;
    /*! The BasicShip object controled by the user*/
    PlayerShip *myShip;

    void spawnPowerUp();
    void MainWindow::keyPressEvent(QKeyEvent *key);
    void MainWindow::keyReleaseEvent(QKeyEvent *key);
    /*! Determines if the level has started or not*/
    bool gameStarted;
    /*! Determines if the level is at the boss or not*/
    bool atBoss;
    /*! Determines which enemies are shooting*/
    bool alternate;
    /*! Containes the calculated score per updateDisplay()*/
    int score;
    /*! The width of the gameScene*/
    int width;
    /*! The height of the gameScene*/
    int height;
    /*! The amount the scrolling background moves*/
    int yDelta;
    /*! Container of all the actions possible by user pressing keys*/
    enum Action {Blank, Left, Right, Up, Down, ShootGun, ShootSBomb, ShootBBomb, Pause};
    /*! Container for to be used in load game*/
    enum String {Background = 0, playerArmor = 1};
    /*! Level object for SuperShooter level*/
    Level *preLevel;
    /*! Bullet object for when a ship shoots a bullet*/
    Bullet *aBullet;
    /*! Big missile object for when a big missile is shot*/
    Missile *aBigMissile;
    /*! Small missile object for when a small missile is shot*/
    Missile *aSmallMissile;
    /*! PowerUp object for when a power up is created*/
    PowerUp *aPU;
    /*! Object to hold the scrolling background*/
    BGround *bg;
    /*! Holds the scene where the entire game is played*/
    QGraphicsScene *gameScene;
    /*! Linked list of all bullets shot*/
    QLinkedList<Bullet*> bulletList;
    /*! Linked list of all missiles shot*/
    QLinkedList<Missile*> missileList;
    /*! ProgressBar object to show boss's armor*/
    QProgressBar *bossLife;
    /*! Pointer to the wave of enemies*/
    QList<BasicShip*>* theWavePtr;
    /*! Timer to timeout when the display updates*/
    QTimer *gameUpdate;
    /*! Timer to timeout when a new powerup is to be created*/
    QTimer *powerUpTimer;
    /*! Timer to timeout when the enemy wave is to shoot*/
    QTimer *enemyShootTimer;
    /*! Timer to timeout when another enemy wave is to be created*/
    QTimer *waveTimer;
    /*! It maps all of the key inputs to actions for the game*/
    QMap<int,Action> actions;
};

#endif // MAINWINDOW_H

