#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BasicShip.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BasicShip myShip(100,100,6);
    if(myShip.getLives() == 3)
    {
        ui->bombsLabel->setText(QString ("$$T$$"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

