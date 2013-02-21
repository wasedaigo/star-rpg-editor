#include "GameDataModel.h"
#include "MapViewModel.h"
#include "ResourceModel.h"
#include "TileSetViewModel.h"

GameDataModel::GameDataModel(QObject *parent) :
    QObject(parent),
    mResourceModel(new ResourceModel(this)),
    mMapViewModel(new MapViewModel(this)),
    mTileSetViewModel(new TileSetViewModel(this, mResourceModel))
{
    mResourceModel->setRootPath("/Users/sato.daigo/Development/git/star-rpg-framework/html/res");
}
