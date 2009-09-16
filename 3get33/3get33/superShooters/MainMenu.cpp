#include "MainMenu.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QPalette>

MainMenu :: QWidget(QWidget *parent)
{

    ~MainMenu();

     //Sets properties of the main window
     mainWindow.resize(640,480);
     mainWindow.setWindowTitle(QString("Super Shooters"));

    //Set the background of the menu
    QPalette p;
    QPixmap pm1(":/images/MenuWithoutButtons640480.jpg");
    p.setBrush(QPalette::Background,  pm1);
    mainWindow.setPalette(p);

    //Setting up 'Play' button
    QPushButton *pb_PlayGame = new QPushButton(&mainWindow);
    pb_PlayGame->setGeometry(220,300,225,42);
    pb_PlayGame->setIconSize(QSize(225,42));
    pb_PlayGame->setIcon(QIcon(":/images/playButton.jpg"));
    pb_PlayGame->setFlat(true);
    pb_PlayGame->show();

    //Setting up 'Level Editor' button
    QPushButton *pb_LevelEditor = new QPushButton(&mainWindow);
    pb_LevelEditor->setGeometry(220,360,225,42);
    pb_LevelEditor->setIconSize(QSize(225,42));
    pb_LevelEditor->setIcon(QIcon(":/images/LevelEditButton.jpg"));
    pb_LevelEditor->setFlat(true);
    pb_LevelEditor->show();

    //Setting up 'Quit' button
    QPushButton *pb_Quit = new QPushButton(&mainWindow);
    pb_Quit->setGeometry(220,420,225,42);
    pb_Quit->setIconSize(QSize(225,42));
    pb_Quit->setIcon(QIcon(":/images/quitButton.jpg"));
    pb_Quit->setFlat(true);
    pb_Quit->show();

    //QObject::connect(pb_PlayGame,SIGNAL(clicked()),&app,
//                                 SLOT(playGameButton(pb_LevelEditor)));

    QObject::connect(pb_Quit,SIGNAL(clicked()),&app,
                             SLOT(quit()));

}

