#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BasicShip.h"
#include <QPushButton>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BasicShip myShip(100,100,3);
    ui->armorDisplay->display(myShip.getArmor());
    ui->sheildDisplay->display(myShip.getShield());
    ui->livesDisplay->display(myShip.getLives());

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**************************************************
 * This SLOT is called when the quitButton is clicked
 */
void MainWindow::closeGame()
{
    this->close();
}
