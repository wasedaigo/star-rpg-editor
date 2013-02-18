#include "GameDataModel.h"
#include "MapViewModel.h"
#include "TileSetViewModel.h"

GameDataModel::GameDataModel(QObject *parent) :
    QObject(parent),
    mMapViewModel(new MapViewModel(this)),
    mTileSetViewModel(new TileSetViewModel(this))
{
}
