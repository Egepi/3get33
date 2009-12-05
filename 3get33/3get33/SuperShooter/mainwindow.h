#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "BasicShip.h"
#include "PlayerShip.h"
#include "Level.h"
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

#include "Bullet.h"
#include "Missile.h"
#include "PowerUp.h"
#include "BasicShip.h"
#include "PlayerShip.h"
#include "Level.h"
#include "bground.h"
#include "ui_mainwindow.h"

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
    void updateArmor();
    void makePowerUp();
    void playerShoot();
    void gamelvl();
    void addingWave();

private:
    Ui::MainWindow *ui;
    PlayerShip *myShip;

    bool gameStarted;
    bool atBoss;
    enum Action {Blank, Left, Right, Up, Down, ShootGun, ShootSBomb, ShootBBomb, Pause};
    enum String {Background = 0, playerArmor = 1};
    QMap<int,Action> actions;
    Level *preLevel;
    Bullet *aBullet;
    Missile *aBigMissile;
    Missile *aSmallMissile;
    QTimer *enemyShootTimer;
    QTimer *waveTimer;
    PowerUp *aPU;
    void MainWindow::keyPressEvent(QKeyEvent *key);
    void MainWindow::keyReleaseEvent(QKeyEvent *key);
    QGraphicsScene *gameScene;
    void spawnPowerUp();
    QLinkedList<Bullet*> bulletList;
    QLinkedList<Missile*> missileList;
    int score;
    int width;
    int height;
    int yDelta;
    BGround *bg;
    QProgressBar *bossLife;
    QList<BasicShip*>* theWavePtr;
    QTimer *gameUpdate;
    QTimer *powerUpTimer;
    bool alternate;


};
#endif // MAINWINDOW_H
