#include<QApplication>
#include "MainMenu.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MainMenu mainWindow;
     mainWindow.show();
     return app.exec();
 }

