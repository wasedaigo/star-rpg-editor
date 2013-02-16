#include "MapViewModel.h"

MapViewModel::MapViewModel(QObject *parent) :
    QObject(parent),
    mActiveLayerType(LayerType_Event)
{
}

void MapViewModel::selectActiveLayer(LayerType layerType) {
    if (mActiveLayerType != layerType) {
        mActiveLayerType = layerType;
        emit activeLayerChanged(layerType);
    }
}
