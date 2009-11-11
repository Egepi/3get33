#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H

#include <QtGui/QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QCombobox>
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <QTextStream>
using namespace std;

namespace Ui
{
    class LevelEditor;
}

class LevelEditor : public QMainWindow
{
    Q_OBJECT

public:
    LevelEditor(QWidget *parent = 0);
    ~LevelEditor();

public slots:
    void categoryChanged(int);
    void savePlayer();
    void writeFile();

private:
    Ui::LevelEditor *ui;
    int previousIndex;
    QPushButton *saveButton;
    QLabel *playerArmor;
    QComboBox *playerArmorIn;
    QLabel *playerShield;
    QComboBox *playerShieldIn;
    QPushButton *saveLevel;

    QString *valuePlayerArmor;
    QString *valuePlayerShield;
    QString *valuePlayerLives;
};

#endif // LEVELEDITOR_H
