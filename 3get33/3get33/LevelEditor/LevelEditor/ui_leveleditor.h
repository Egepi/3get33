/********************************************************************************
** Form generated from reading ui file 'leveleditor.ui'
**
** Created: Tue Nov 10 12:55:32 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LEVELEDITOR_H
#define UI_LEVELEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelEditor
{
public:
    QWidget *centralWidget;
    QComboBox *categoryCombo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LevelEditor)
    {
        if (LevelEditor->objectName().isEmpty())
            LevelEditor->setObjectName(QString::fromUtf8("LevelEditor"));
        LevelEditor->setEnabled(true);
        LevelEditor->resize(600, 400);
        centralWidget = new QWidget(LevelEditor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        categoryCombo = new QComboBox(centralWidget);
        categoryCombo->setObjectName(QString::fromUtf8("categoryCombo"));
        categoryCombo->setGeometry(QRect(20, 40, 121, 21));
        LevelEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LevelEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        LevelEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LevelEditor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LevelEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LevelEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LevelEditor->setStatusBar(statusBar);

        retranslateUi(LevelEditor);

        QMetaObject::connectSlotsByName(LevelEditor);
    } // setupUi

    void retranslateUi(QMainWindow *LevelEditor)
    {
        LevelEditor->setWindowTitle(QApplication::translate("LevelEditor", "LevelEditor", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(LevelEditor);
    } // retranslateUi

};

namespace Ui {
    class LevelEditor: public Ui_LevelEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELEDITOR_H
