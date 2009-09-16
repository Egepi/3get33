#include<QtGui/QApplication>
#include "MainMenu.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     MainMenu mainWin();
     return app.exec();
 }

