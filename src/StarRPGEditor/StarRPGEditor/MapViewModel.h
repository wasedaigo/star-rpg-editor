#ifndef MAPVIEWMODEL_H
#define MAPVIEWMODEL_H

#include <QObject>
class MapViewModel : public QObject
{
    Q_OBJECT

public:
    enum LayerType {
        LayerType_Event,
        LayerType_Panorama,
        LayerType_Bottom,
        LayerType_Middle,
        LayerType_Top,
        LayerType_Sky,
        LayerType_COUNT
    };

    explicit MapViewModel(QObject *parent);

    void selectActiveLayer(LayerType layerType);

signals:
    void activeLayerChanged(LayerType layerType);

private:
    LayerType mActiveLayerType;

};

#endif // MAPVIEWMODEL_H
