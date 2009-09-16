//#include "main.h"
#include <QApplication>
#include <QPushButton>
#include <QLabel>

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QWidget mainWindow;

     mainWindow.resize(640,480);
     mainWindow.setWindowTitle(QString("Super Shooters"));
     mainWindow.show();

     QLabel background(&mainWindow);
     QString backgroundPath = QApplication::applicationFilePath();
     //background.setText(backgroundPath);
     background.setPixmap(QPixmap(":/smile.jpg"));
     background.show();

     return app.exec();
 }
