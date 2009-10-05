#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BasicShip.h"
#include <QPushButton>
#include <QObject>
#include <QPixmap>
#include <QGraphicsScene>

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

#endif // MAINWINDOW_H
