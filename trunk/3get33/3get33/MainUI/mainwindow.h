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

private:
    Ui::MainWindow *ui;

};



class MyScene : public QGraphicsScene {

    void keyPressEvent(QKeyEvent *key) {
        switch(key->key()) {
            case Qt::Key_Left:
            setBackgroundBrush(Qt::blue);
            break;
            case Qt::Key_Right:
            setBackgroundBrush(Qt::red);
            break;
            case Qt::Key_Up:
            setBackgroundBrush(Qt::green);
            break;
            case Qt::Key_Down:
            setBackgroundBrush(Qt::yellow);
            break;
            case Qt::Key_B:
            setBackgroundBrush(Qt::black);
            break;
            case Qt::Key_Space:
            setBackgroundBrush(Qt::white);
            break;
            default:
            cout << "key pressed " << endl << flush;
        }

    }
};
#endif // MAINWINDOW_H
