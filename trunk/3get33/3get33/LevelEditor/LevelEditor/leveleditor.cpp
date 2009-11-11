#include "leveleditor.h"
#include "ui_leveleditor.h"

LevelEditor::LevelEditor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LevelEditor)
{
    previousIndex = -1;
    valuePlayerArmor = 1;
    valuePlayerShield = 1;
    valuePlayerLives = 0;
    valuePlayerBigBombs = 0;
    valuePlayerSmallBombs = 0;
    ui->setupUi(this);

    ui->categoryCombo->addItem(QString("<Select Category>"));
    ui->categoryCombo->addItem(QString("Player Ship"));
    ui->categoryCombo->addItem(QString("Level"));
    ui->categoryCombo->addItem(QString("Boss"));

    /**********************************************************/
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

    for(int i = 0; i < 250; i++)
    {
        QString addValue;
        addValue = addValue.setNum(i+1);
        playerShieldIn->addItem(addValue);
        playerArmorIn->addItem(addValue);
    }

    playerLives = new QLabel(QString("Player's Starting number\nof lives"),this);
    playerLives->setGeometry(200,106,117,40);
    playerLives->hide();

    playerLivesIn = new QComboBox(this);
    playerLivesIn->setGeometry(200,141,115,25);
    playerLivesIn->hide();

    for(int i=0; i < 11; i++)
    {
        QString addValue;
        addValue = addValue.setNum(i);
        playerLivesIn->addItem(addValue);
    }

    playerSmallBomb = new QLabel(QString("Number of starting\nsmall bombs"),this);
    playerSmallBomb->setGeometry(365,106,115,40);
    playerSmallBomb->hide();

    playerSmallBombIn = new QComboBox(this);
    playerSmallBombIn->setGeometry(365,141,115,25);
    playerSmallBombIn->hide();

    playerBigBomb = new QLabel(QString("Number of starting\nbig bombs"),this);
    playerBigBomb->setGeometry(200,165,115,40);
    playerBigBomb->hide();

    playerBigBombIn = new QComboBox(this);
    playerBigBombIn->setGeometry(200,200,115,25);
    playerBigBombIn->hide();

    for(int i=0; i < 100; i++)
    {
        QString addValue;
        addValue = addValue.setNum(i);
        playerSmallBombIn->addItem(addValue);
        playerBigBombIn->addItem(addValue);
    }


    /**********************************************************/
    saveButton = new QPushButton(this);
    saveButton->setGeometry(20,81,100,30);
    saveButton->setText(QString("Save Settings"));
    saveButton->hide();
    QObject::connect(saveButton, SIGNAL(clicked()), this, SLOT(savePlayer()));

    saveLevel = new QPushButton(this);
    saveLevel->setGeometry(20,113,100,30);
    saveLevel->setText(QString("Finished and Exit"));
    saveLevel->show();
    QObject::connect(saveLevel, SIGNAL(clicked()), this, SLOT(writeFile()));

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
        playerArmorIn->setCurrentIndex(valuePlayerArmor-1);
        playerArmorIn->hide();
        playerShield->hide();
        playerShieldIn->setCurrentIndex(valuePlayerShield-1);
        playerShieldIn->hide();
        playerLives->hide();
        playerLivesIn->hide();
        playerSmallBombIn->hide();
        playerSmallBomb->hide();
        playerBigBombIn->hide();
        playerBigBomb->hide();
    }
    if(theIndex == 1)
    {
        playerArmor->show();
        playerArmorIn->setCurrentIndex(valuePlayerArmor-1);
        playerArmorIn->show();

        playerShield->show();
        playerShieldIn->setCurrentIndex(valuePlayerShield-1);
        playerShieldIn->show();

        playerLives->show();
        playerLivesIn->show();

        playerSmallBomb->show();
        playerSmallBombIn->show();

        playerBigBombIn->show();
        playerBigBomb->show();

        //ui->categoryCombo->setDisabled(true);
        saveButton->show();

        previousIndex = ui->categoryCombo->currentIndex();
    }
}

void LevelEditor::savePlayer()
{
    valuePlayerArmor = playerArmorIn->currentIndex()+1;
    valuePlayerShield = playerShieldIn->currentIndex()+1;
    ui->categoryCombo->setDisabled(false);
}

void LevelEditor::writeFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, QString("Enter File Name"));
    QFile f(fileName);
    f.open(QIODevice::WriteOnly);
        QTextStream stream(&f);
        //stream<<"PlayerArmor#"<<playerArmorIn->currentText() << "\n";
        //stream<<"PlayerShield#"<<playerShieldIn->currentText() <<"\n";
    f.close();

    this->close();

}

