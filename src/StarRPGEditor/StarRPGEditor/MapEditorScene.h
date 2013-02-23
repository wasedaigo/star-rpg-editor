#ifndef MAPEDITORSCENE_H
#define MAPEDITORSCENE_H

#include <QWidget>

namespace Ui {
class MapEditorScene;
}

class GameDataModel;
class MapEventListView;
class TilePaletteView;
class MapTreeView;
class MapView;

class MapEditorScene : public QWidget
{
    Q_OBJECT
    
public:
    explicit MapEditorScene(QWidget *parent, GameDataModel *gameDataModel);
    ~MapEditorScene();

private:
    QScopedPointer<Ui::MapEditorScene> mUI;
    MapEventListView *mMapEventListView;
    TilePaletteView *mTilePaletteView;
    MapTreeView *mMapTreeView;
    MapView *mMapView;
};

#endif // MAPEDITORSCENE_H
