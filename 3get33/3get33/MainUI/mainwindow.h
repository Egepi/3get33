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
    void MainWindow::keyPressEvent(QKeyEvent *key);
    void MainWindow::keyReleaseEvent(QKeyEvent *key);
    void gamelvl();

public slots:
    void closeGame();
    void loadGame();
    void playGame();
    void checkQuit();

private:
    Ui::MainWindow *ui;
    PlayerShip *myShip;
    BasicShip *Enemy1;
    BasicShip *Enemy2;
    QGraphicsScene *gameScene;
    bool gameStarted;
    enum Action {Blank, Left, Right, Up, Down, ShootGun, ShootSBomb, ShootBBomb, Pause};
    QMap<int,Action> actions;
    Level *preLevel;


};
#endif // MAINWINDOW_H

