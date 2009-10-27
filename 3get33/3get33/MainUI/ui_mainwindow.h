/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue Oct 27 17:34:43 2009
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
    QLCDNumber *sheildDisplay;
    QLCDNumber *armorDisplay;
    QLCDNumber *bigBombDisplay;
    QLCDNumber *smallBombsDisplay;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 480);
        MainWindow->setMinimumSize(QSize(740, 480));
        MainWindow->setMaximumSize(QSize(740, 480));
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
        Display->setGeometry(QRect(140, 0, 600, 480));
        Display->setFrameShape(QFrame::NoFrame);
        Display->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Display->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(0, 20, 140, 50));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(0, 130, 140, 50));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(0, 75, 140, 50));
        scoreDisplay = new QLCDNumber(centralWidget);
        scoreDisplay->setObjectName(QString::fromUtf8("scoreDisplay"));
        scoreDisplay->setGeometry(QRect(50, 440, 80, 30));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        scoreDisplay->setPalette(palette1);
        scoreDisplay->setAutoFillBackground(true);
        scoreDisplay->setFrameShape(QFrame::Box);
        scoreDisplay->setFrameShadow(QFrame::Raised);
        scoreDisplay->setNumDigits(5);
        scoreDisplay->setSegmentStyle(QLCDNumber::Flat);
        scoreDisplay->setProperty("value", QVariant(0));
        scoreDisplay->setProperty("intValue", QVariant(0));
        scoreLabel = new QLabel(centralWidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setGeometry(QRect(10, 440, 40, 30));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        scoreLabel->setPalette(palette2);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Gothic"));
        font.setPointSize(9);
        scoreLabel->setFont(font);
        livesLabel = new QLabel(centralWidget);
        livesLabel->setObjectName(QString::fromUtf8("livesLabel"));
        livesLabel->setGeometry(QRect(10, 410, 40, 30));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        livesLabel->setPalette(palette3);
        livesLabel->setFont(font);
        livesDisplay = new QLCDNumber(centralWidget);
        livesDisplay->setObjectName(QString::fromUtf8("livesDisplay"));
        livesDisplay->setGeometry(QRect(50, 410, 80, 30));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush3(QColor(255, 144, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        livesDisplay->setPalette(palette4);
        livesDisplay->setAutoFillBackground(true);
        livesDisplay->setFrameShape(QFrame::Box);
        livesDisplay->setFrameShadow(QFrame::Raised);
        livesDisplay->setNumDigits(3);
        livesDisplay->setSegmentStyle(QLCDNumber::Flat);
        livesDisplay->setProperty("value", QVariant(0));
        livesDisplay->setProperty("intValue", QVariant(0));
        armorLabel = new QLabel(centralWidget);
        armorLabel->setObjectName(QString::fromUtf8("armorLabel"));
        armorLabel->setGeometry(QRect(10, 380, 40, 30));
        QPalette palette5;
        QBrush brush4(QColor(255, 85, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        armorLabel->setPalette(palette5);
        armorLabel->setFont(font);
        sheildLabel = new QLabel(centralWidget);
        sheildLabel->setObjectName(QString::fromUtf8("sheildLabel"));
        sheildLabel->setGeometry(QRect(10, 350, 40, 30));
        QPalette palette6;
        QBrush brush5(QColor(0, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        sheildLabel->setPalette(palette6);
        sheildLabel->setFont(font);
        bombsLabel = new QLabel(centralWidget);
        bombsLabel->setObjectName(QString::fromUtf8("bombsLabel"));
        bombsLabel->setGeometry(QRect(60, 270, 40, 30));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        bombsLabel->setPalette(palette7);
        bombsLabel->setFont(font);
        sheildDisplay = new QLCDNumber(centralWidget);
        sheildDisplay->setObjectName(QString::fromUtf8("sheildDisplay"));
        sheildDisplay->setGeometry(QRect(50, 350, 80, 30));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush6(QColor(0, 85, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        sheildDisplay->setPalette(palette8);
        sheildDisplay->setAutoFillBackground(true);
        sheildDisplay->setFrameShape(QFrame::Box);
        sheildDisplay->setFrameShadow(QFrame::Raised);
        sheildDisplay->setNumDigits(3);
        sheildDisplay->setSegmentStyle(QLCDNumber::Flat);
        sheildDisplay->setProperty("value", QVariant(0));
        sheildDisplay->setProperty("intValue", QVariant(0));
        armorDisplay = new QLCDNumber(centralWidget);
        armorDisplay->setObjectName(QString::fromUtf8("armorDisplay"));
        armorDisplay->setGeometry(QRect(50, 380, 80, 30));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush7(QColor(255, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        armorDisplay->setPalette(palette9);
        armorDisplay->setAutoFillBackground(true);
        armorDisplay->setFrameShape(QFrame::Box);
        armorDisplay->setFrameShadow(QFrame::Raised);
        armorDisplay->setNumDigits(3);
        armorDisplay->setSegmentStyle(QLCDNumber::Flat);
        armorDisplay->setProperty("value", QVariant(0));
        armorDisplay->setProperty("intValue", QVariant(0));
        bigBombDisplay = new QLCDNumber(centralWidget);
        bigBombDisplay->setObjectName(QString::fromUtf8("bigBombDisplay"));
        bigBombDisplay->setGeometry(QRect(80, 320, 51, 30));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush8(QColor(0, 255, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        bigBombDisplay->setPalette(palette10);
        bigBombDisplay->setAutoFillBackground(true);
        bigBombDisplay->setFrameShape(QFrame::Box);
        bigBombDisplay->setFrameShadow(QFrame::Raised);
        bigBombDisplay->setNumDigits(2);
        bigBombDisplay->setSegmentStyle(QLCDNumber::Flat);
        bigBombDisplay->setProperty("value", QVariant(0));
        bigBombDisplay->setProperty("intValue", QVariant(0));
        smallBombsDisplay = new QLCDNumber(centralWidget);
        smallBombsDisplay->setObjectName(QString::fromUtf8("smallBombsDisplay"));
        smallBombsDisplay->setGeometry(QRect(30, 320, 51, 30));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Base, brush);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        smallBombsDisplay->setPalette(palette11);
        smallBombsDisplay->setAutoFillBackground(true);
        smallBombsDisplay->setFrameShape(QFrame::Box);
        smallBombsDisplay->setFrameShadow(QFrame::Raised);
        smallBombsDisplay->setNumDigits(2);
        smallBombsDisplay->setSegmentStyle(QLCDNumber::Flat);
        smallBombsDisplay->setProperty("value", QVariant(0));
        smallBombsDisplay->setProperty("intValue", QVariant(0));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 300, 91, 20));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette12);
        label->setFont(font);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(quitButton, SIGNAL(clicked()), MainWindow, SLOT(closeGame()));
        QObject::connect(loadButton, SIGNAL(clicked()), MainWindow, SLOT(loadGame()));
        QObject::connect(playButton, SIGNAL(clicked()), MainWindow, SLOT(playGame()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Super Shooters", 0, QApplication::UnicodeUTF8));
        playButton->setText(QString());
        quitButton->setText(QString());
        loadButton->setText(QString());
        scoreLabel->setText(QApplication::translate("MainWindow", "Score", 0, QApplication::UnicodeUTF8));
        livesLabel->setText(QApplication::translate("MainWindow", "Lives", 0, QApplication::UnicodeUTF8));
        armorLabel->setText(QApplication::translate("MainWindow", "Armor", 0, QApplication::UnicodeUTF8));
        sheildLabel->setText(QApplication::translate("MainWindow", "Sheild", 0, QApplication::UnicodeUTF8));
        bombsLabel->setText(QApplication::translate("MainWindow", "Bombs", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Small:   Large:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
