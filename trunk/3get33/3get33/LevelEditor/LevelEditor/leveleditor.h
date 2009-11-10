#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H

#include <QtGui/QMainWindow>

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

private:
    Ui::LevelEditor *ui;
};

#endif // LEVELEDITOR_H
