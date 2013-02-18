#ifndef DATABASETILESETVIEW_H
#define DATABASETILESETVIEW_H

#include <QWidget>

namespace Ui {
class DatabaseTileSetView;
}
class MaterialSelectDialog;
class ResourceModel;

class DatabaseTileSetView : public QWidget
{
    Q_OBJECT
public:
    explicit DatabaseTileSetView(QWidget *parent, ResourceModel *resourceModel);
    ~DatabaseTileSetView();

private slots:
    void groundAssetSelectButtonClicked();

signals:
    
private:
    QScopedPointer<Ui::DatabaseTileSetView> mUI;
    MaterialSelectDialog *mMaterialSelectDialog;
};

#endif // DATABASETILESETVIEW_H
