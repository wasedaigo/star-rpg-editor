#ifndef GAMEDATAMODEL_H
#define GAMEDATAMODEL_H

#include <QObject>
#include <QStringList>

class MapViewModel;
class TileSetViewModel;
class GameDataModel : public QObject
{
    Q_OBJECT

public:
    explicit GameDataModel(QObject *parent = 0);

public:
    //EventViewModel mEventViewModel;
    MapViewModel *mMapViewModel;
    TileSetViewModel *mTileSetViewModel;
    //CharaSetViewModel mCharaSetViewModel;
    //SwitchViewModel mSwitchViewModel;
    //VariableViewModel mVariableViewModel;
};

#endif // GAMEDATAMODEL_H
