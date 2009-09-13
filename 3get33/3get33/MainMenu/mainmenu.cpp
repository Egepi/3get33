#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

//This method is called when pb_QuitGame is clicked()
void MainMenu::quitGame()
{
    QMainWindow::close();   //This closes the MainMenu
}
