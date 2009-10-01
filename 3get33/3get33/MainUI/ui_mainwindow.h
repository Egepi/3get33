/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Oct 1 08:58:55 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *Display;
    QPushButton *playButton;
    QPushButton *quitButton;
    QPushButton *loadButton;
    QLCDNumber *scoreDisplay;
    QLabel *scoreLabel;
    QLabel *livesLabel;
    QLCDNumber *livesDisplay;
    QLabel *armorLabel;
    QLabel *sheildLabel;
    QLabel *bombsLabel;
    QLCDNumber *bombsDisplay;
    QLCDNumber *sheildDisplay;
    QLCDNumber *armorDisplay;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Display = new QGraphicsView(centralWidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        Display->setGeometry(QRect(140, 0, 500, 480));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(0, 20, 140, 50));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(0, 120, 140, 50));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(0, 70, 140, 50));
        scoreDisplay = new QLCDNumber(centralWidget);
        scoreDisplay->setObjectName(QString::fromUtf8("scoreDisplay"));
        scoreDisplay->setGeometry(QRect(50, 440, 80, 30));
        scoreDisplay->setFrameShape(QFrame::Box);
        scoreDisplay->setFrameShadow(QFrame::Raised);
        scoreDisplay->setNumDigits(5);
        scoreDisplay->setSegmentStyle(QLCDNumber::Flat);
        scoreDisplay->setProperty("value", QVariant(0));
        scoreDisplay->setProperty("intValue", QVariant(0));
        scoreLabel = new QLabel(centralWidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setGeometry(QRect(10, 440, 40, 30));
        livesLabel = new QLabel(centralWidget);
        livesLabel->setObjectName(QString::fromUtf8("livesLabel"));
        livesLabel->setGeometry(QRect(10, 410, 40, 30));
        livesDisplay = new QLCDNumber(centralWidget);
        livesDisplay->setObjectName(QString::fromUtf8("livesDisplay"));
        livesDisplay->setGeometry(QRect(50, 410, 80, 30));
        livesDisplay->setFrameShape(QFrame::Box);
        livesDisplay->setFrameShadow(QFrame::Raised);
        livesDisplay->setNumDigits(5);
        livesDisplay->setSegmentStyle(QLCDNumber::Flat);
        livesDisplay->setProperty("value", QVariant(0));
        livesDisplay->setProperty("intValue", QVariant(0));
        armorLabel = new QLabel(centralWidget);
        armorLabel->setObjectName(QString::fromUtf8("armorLabel"));
        armorLabel->setGeometry(QRect(10, 380, 40, 30));
        sheildLabel = new QLabel(centralWidget);
        sheildLabel->setObjectName(QString::fromUtf8("sheildLabel"));
        sheildLabel->setGeometry(QRect(10, 350, 40, 30));
        bombsLabel = new QLabel(centralWidget);
        bombsLabel->setObjectName(QString::fromUtf8("bombsLabel"));
        bombsLabel->setGeometry(QRect(10, 320, 40, 30));
        bombsDisplay = new QLCDNumber(centralWidget);
        bombsDisplay->setObjectName(QString::fromUtf8("bombsDisplay"));
        bombsDisplay->setGeometry(QRect(50, 320, 80, 30));
        bombsDisplay->setFrameShape(QFrame::Box);
        bombsDisplay->setFrameShadow(QFrame::Raised);
        bombsDisplay->setNumDigits(5);
        bombsDisplay->setSegmentStyle(QLCDNumber::Flat);
        bombsDisplay->setProperty("value", QVariant(0));
        bombsDisplay->setProperty("intValue", QVariant(0));
        sheildDisplay = new QLCDNumber(centralWidget);
        sheildDisplay->setObjectName(QString::fromUtf8("sheildDisplay"));
        sheildDisplay->setGeometry(QRect(50, 350, 80, 30));
        sheildDisplay->setFrameShape(QFrame::Box);
        sheildDisplay->setFrameShadow(QFrame::Raised);
        sheildDisplay->setNumDigits(5);
        sheildDisplay->setSegmentStyle(QLCDNumber::Flat);
        sheildDisplay->setProperty("value", QVariant(0));
        sheildDisplay->setProperty("intValue", QVariant(0));
        armorDisplay = new QLCDNumber(centralWidget);
        armorDisplay->setObjectName(QString::fromUtf8("armorDisplay"));
        armorDisplay->setGeometry(QRect(50, 380, 80, 30));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        armorDisplay->setPalette(palette1);
        armorDisplay->setAutoFillBackground(true);
        armorDisplay->setFrameShape(QFrame::Box);
        armorDisplay->setFrameShadow(QFrame::Raised);
        armorDisplay->setNumDigits(5);
        armorDisplay->setSegmentStyle(QLCDNumber::Flat);
        armorDisplay->setProperty("value", QVariant(0));
        armorDisplay->setProperty("intValue", QVariant(0));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Super Shooters", 0, QApplication::UnicodeUTF8));
        playButton->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("MainWindow", "Load Game", 0, QApplication::UnicodeUTF8));
        scoreLabel->setText(QApplication::translate("MainWindow", "Score", 0, QApplication::UnicodeUTF8));
        livesLabel->setText(QApplication::translate("MainWindow", "Lives", 0, QApplication::UnicodeUTF8));
        armorLabel->setText(QApplication::translate("MainWindow", "Armor", 0, QApplication::UnicodeUTF8));
        sheildLabel->setText(QApplication::translate("MainWindow", "Sheild", 0, QApplication::UnicodeUTF8));
        bombsLabel->setText(QApplication::translate("MainWindow", "Bombs", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
