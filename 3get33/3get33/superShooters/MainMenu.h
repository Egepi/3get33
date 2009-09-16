#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QMainWindow>

namespace Ui
{
    class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = 0);
    ~MainMenu();

private:
    QWidget *mainWindow;
    QPushButton *pb_PlayGame;
    QPushButton *pb_LevelEditor;
    QPushButton *pb_Quit;
    QPalette p;
    //QPixmap pm1;


};

#endif // MAINMENU_H
