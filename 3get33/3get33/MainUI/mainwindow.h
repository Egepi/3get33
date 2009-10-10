#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
#include "BasicShip.h"
#include <QPushButton>
#include <QObject>
#include <QPixmap>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "PlayerShip.h"


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

public slots:
    void closeGame();
    void loadGame();
    void playGame();

private:
    Ui::MainWindow *ui;
    PlayerShip *myShip;
    QGraphicsScene *gameScene;
    bool gameStarted;
    enum Action { Left, Right, Up, Down, ShootGun, ShootSBomb, ShootBBomb, Pause};
    QMap<int,Action> actions;

};
#endif // MAINWINDOW_H
