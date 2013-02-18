#include "DatabaseTileSetView.h"
#include "DatabaseListView.h"
#include "MaterialSelectDialog.h"
#include "ResourceModel.h"
#include "ui_database_tile_set_view.h"
#include <QHBoxLayout>

DatabaseTileSetView::DatabaseTileSetView(QWidget *parent, ResourceModel *resourceModel) :
    QWidget(parent),
    mUI(new Ui::DatabaseTileSetView),
    mMaterialSelectDialog(new MaterialSelectDialog(this, resourceModel))
{
    mUI->setupUi(this);
    QObject::connect(mUI->groundAssetSelectButton, SIGNAL(clicked()), this, SLOT(groundAssetSelectButtonClicked()));
}

DatabaseTileSetView::~DatabaseTileSetView() {
}

void DatabaseTileSetView::groundAssetSelectButtonClicked() {
    mMaterialSelectDialog->setResourceType(ResourceModel::ResourceType_TileSet);
    mMaterialSelectDialog->exec();
}
