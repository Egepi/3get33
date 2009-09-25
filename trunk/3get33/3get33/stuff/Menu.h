#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QMainWindow>

namespace Ui
{
    class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = 0);
    ~Menu();

private:
    QWidget *mainWindow;
    QPushButton *pb_PlayGame;
    QPushButton *pb_LevelEditor;
    QPushButton *pb_Quit;
    QPalette p;
    //QPixmap pm1;


};

#endif //MENU_H
