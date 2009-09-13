/********************************************************************************
** Form generated from reading ui file 'mainmenu.ui'
**
** Created: Sat Sep 12 19:47:27 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralWidget;
    QPushButton *pb_PlayGame;
    QPushButton *pb_LevelEditor;
    QPushButton *pb_Quit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(640, 480);
        centralWidget = new QWidget(MainMenu);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pb_PlayGame = new QPushButton(centralWidget);
        pb_PlayGame->setObjectName(QString::fromUtf8("pb_PlayGame"));
        pb_PlayGame->setGeometry(QRect(260, 242, 120, 41));
        pb_LevelEditor = new QPushButton(centralWidget);
        pb_LevelEditor->setObjectName(QString::fromUtf8("pb_LevelEditor"));
        pb_LevelEditor->setGeometry(QRect(260, 300, 120, 41));
        pb_Quit = new QPushButton(centralWidget);
        pb_Quit->setObjectName(QString::fromUtf8("pb_Quit"));
        pb_Quit->setGeometry(QRect(260, 358, 120, 41));
        MainMenu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainMenu);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 22));
        MainMenu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainMenu);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainMenu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainMenu);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainMenu->setStatusBar(statusBar);

        retranslateUi(MainMenu);
        QObject::connect(pb_Quit, SIGNAL(clicked()), MainMenu, SLOT(quitGame()));

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainMenu", 0, QApplication::UnicodeUTF8));
        pb_PlayGame->setText(QApplication::translate("MainMenu", "Play Game", 0, QApplication::UnicodeUTF8));
        pb_LevelEditor->setText(QApplication::translate("MainMenu", "Level Editor", 0, QApplication::UnicodeUTF8));
        pb_Quit->setText(QApplication::translate("MainMenu", "Quit", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainMenu);
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
