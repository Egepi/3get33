#include "leveleditor.h"
#include "ui_leveleditor.h"

LevelEditor::LevelEditor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LevelEditor)
{
    previousIndex = -1;
    valuePlayerArmor = new QString("100");
    valuePlayerLives = new QString("3");
    valuePlayerShield = new QString("100");
    ui->setupUi(this);



    ui->categoryCombo->addItem(QString("<Select Category>"));
    ui->categoryCombo->addItem(QString("Player Ship"));
    ui->categoryCombo->addItem(QString("Level"));
    ui->categoryCombo->addItem(QString("Boss"));

    playerArmorIn = new QComboBox(this);
    playerArmorIn->setGeometry(200,80,115,25);
    playerArmorIn->hide();

    playerArmor = new QLabel(QString("Player's default Armor\n (Between 1 and 250)"),this);
    playerArmor->setGeometry(200,40,115,40);
    playerArmor->hide();

    playerShield = new QLabel(QString("Player's default Shield\n (Between 1 and 250)"),this);
    playerShield->setGeometry(365,40,115,40);
    playerShield->hide();

    playerShieldIn = new QComboBox(this);
    playerShieldIn->setGeometry(365,80,115,25);
    playerShieldIn->hide();

    saveButton = new QPushButton(this);
    saveButton->setGeometry(20,81,100,30);
    saveButton->setText(QString("Save Settings"));
    saveButton->hide();
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(savePlayer()));

    saveLevel = new QPushButton(this);
    saveLevel->setGeometry(20,113,100,30);
    saveLevel->setText(QString("Finished and Exit"));
    //saveLevel->setDisabled(true);
    saveLevel->show();
    QObject::connect(saveLevel, SIGNAL(clicked()), this, SLOT(writeFile()));




    for(int i = 0; i < 250; i++)
    {
        QString addValue;
        addValue = addValue.setNum(i+1);
        playerShieldIn->addItem(addValue);
        playerArmorIn->addItem(addValue);

    }

    QObject::connect(ui->categoryCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(categoryChanged(int)));



}

LevelEditor::~LevelEditor()
{
    delete ui;
}

void LevelEditor::categoryChanged(int theIndex)
{
    if(previousIndex != -1)
    {
        playerArmor->hide();
        playerArmorIn->hide();
        playerShield->hide();
        playerShieldIn->hide();
    }
    if(theIndex == 1)
    {
        playerArmor->show();
        playerArmorIn->show();

        playerShield->show();
        playerShieldIn->show();

        ui->categoryCombo->setDisabled(true);
        saveButton->show();

        previousIndex = ui->categoryCombo->currentIndex();
    }
}

void LevelEditor::savePlayer()
{
    valuePlayerArmor = new QString(playerArmorIn->currentText());
    ui->categoryCombo->setDisabled(false);
}

void LevelEditor::writeFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, QString("Enter File Name"));
    QFile f(fileName);
    f.open(QIODevice::WriteOnly);
        QTextStream stream(&f);
        stream<<"PlayerArmor#"<<playerArmorIn->currentText() << "\n";
        stream<<"PlayerShield#"<<playerShieldIn->currentText() <<"\n";
    f.close();

    this->close();

}

