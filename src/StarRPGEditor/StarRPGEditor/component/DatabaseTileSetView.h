#ifndef DATABASETILESETVIEW_H
#define DATABASETILESETVIEW_H

#include <QWidget>

namespace Ui {
class DatabaseTileSetView;
}
class MaterialSelectDialog;
class ResourceModel;
class TileSetViewModel;
class TilePaletteGraphicsView;

class DatabaseTileSetView : public QWidget
{
    Q_OBJECT
public:
    explicit DatabaseTileSetView(QWidget *parent, ResourceModel *resourceModel, TileSetViewModel *tileSetViewModel);
    ~DatabaseTileSetView();

private slots:
    void groundAssetSelectButtonClicked();

signals:
    
private:
    QScopedPointer<Ui::DatabaseTileSetView> mUI;
    MaterialSelectDialog *mMaterialSelectDialog;
    TilePaletteGraphicsView *mTilePaletteGraphicsView;
    TileSetViewModel *mTileSetViewModel;
};

#endif // DATABASETILESETVIEW_H
