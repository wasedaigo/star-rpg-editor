#ifndef DATABASESCENE_H
#define DATABASESCENE_H

#include <QWidget>

namespace Ui {
class DatabaseScene;
}

class GameDataModel;
class DatabaseScene : public QWidget
{
    Q_OBJECT
public:
    explicit DatabaseScene(QWidget *parent, GameDataModel *gameDataModel);
    ~DatabaseScene();

signals:
    
public slots:

private:
    QScopedPointer<Ui::DatabaseScene> mUI;
};

#endif // DATABASESCENE_H
