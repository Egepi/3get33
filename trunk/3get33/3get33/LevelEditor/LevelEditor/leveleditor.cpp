#include "leveleditor.h"
#include "ui_leveleditor.h"

LevelEditor::LevelEditor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LevelEditor)
{
    ui->setupUi(this);
    QStringList categoryList();
    //categoryList<<"Background Image";
    ui->categoryCombo->addItem(QString("lala"));
    ui->categoryCombo->addItem(QString("lblb"));
}

LevelEditor::~LevelEditor()
{
    delete ui;
}
