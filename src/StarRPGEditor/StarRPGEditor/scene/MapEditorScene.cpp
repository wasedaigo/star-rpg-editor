#include "BaseScene.h"
#include "MapEditorScene.h"
#include "MapEventListView.h"
#include "MapTreeView.h"
#include "MapView.h"
#include "GameDataModel.h"
#include "TilePaletteView.h"
#include "ui_map_editor_scene.h"

MapEditorScene::MapEditorScene(QWidget *parent, NavigationController *navigationController, GameDataModel *gameDataModel) :
    BaseScene(parent, navigationController),
    mUI(new Ui::MapEditorScene),
    mMapEventListView(new MapEventListView(this)),
    mTilePaletteView(new TilePaletteView(this, gameDataModel->mTileSetViewModel)),
    mMapTreeView(new MapTreeView(this)),
    mMapView(new MapView(this, gameDataModel->mMapViewModel))
{
    mUI->setupUi(this);
    mUI->eventListPage->layout()->addWidget(mMapEventListView);
    mUI->palettePage->layout()->addWidget(mTilePaletteView);
    mUI->mapTreeFrame->layout()->addWidget(mMapTreeView);
    mUI->rightContainer->layout()->addWidget(mMapView);
    mUI->stackedWidget->setCurrentIndex(0);

    mTilePaletteView->loadPalette();
}

MapEditorScene::~MapEditorScene() {
}
