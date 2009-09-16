//#include "main.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QPalette>



 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QWidget mainWindow;

     mainWindow.resize(640,480);
     mainWindow.setWindowTitle(QString("Super Shooters"));
     mainWindow.show();

    //Set the background
    QPalette p;
    QPixmap pm1(":/images/MenuWithoutButtons640480.jpg");
    p.setBrush(QPalette::Background,  pm1);
    mainWindow.setPalette(p);

    //Add buttons onto the window
    //QPushButton playButton(&mainWindow);
    //QPushButton levelEditButton(&mainWindow);
    //QPushButton quitButton(&mainWindow);

    //playButton.setIcon(QIcon(":/images/playButton.jpg"));
    //levelEditButton.setIcon(QIcon(":/images/LevelEditButton.jpg"));
    //quitButton.setIcon(QIcon(":/images/quitButton.jpg"));

   // playButton.show();
    //levelEditButton.show();
    //quitButton.show();

     return app.exec();
 }
