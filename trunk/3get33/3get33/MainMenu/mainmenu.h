#ifndef MAINMENU_H
#define MAINMENU_H

#include <QtGui/QMainWindow>

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
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
