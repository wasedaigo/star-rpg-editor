#ifndef DATABASESCENE_H
#define DATABASESCENE_H

#include "BaseScene.h"

namespace Ui {
class DatabaseScene;
}

class GameDataModel;
class NavigationController;

class DatabaseScene : public BaseScene
{
    Q_OBJECT
public:
    explicit DatabaseScene(QWidget *parent, NavigationController *navigationController, GameDataModel *gameDataModel);
    ~DatabaseScene();

signals:
    
public slots:

private:
    QScopedPointer<Ui::DatabaseScene> mUI;
};

#endif // DATABASESCENE_H
