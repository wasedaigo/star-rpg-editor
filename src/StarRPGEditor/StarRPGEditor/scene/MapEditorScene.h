#ifndef MAPEDITORSCENE_H
#define MAPEDITORSCENE_H

#include "BaseScene.h"

namespace Ui {
class MapEditorScene;
}

class GameDataModel;
class MapEventListView;
class TilePaletteView;
class MapTreeView;
class MapView;
class NavigationController;

class MapEditorScene : public BaseScene
{
    Q_OBJECT
    
public:
    explicit MapEditorScene(QWidget *parent, NavigationController *navigationController, GameDataModel *gameDataModel);
    ~MapEditorScene();

private:
    QScopedPointer<Ui::MapEditorScene> mUI;
    MapEventListView *mMapEventListView;
    TilePaletteView *mTilePaletteView;
    MapTreeView *mMapTreeView;
    MapView *mMapView;
};

#endif // MAPEDITORSCENE_H
