#include "DatabaseTileSetView.h"
#include "DatabaseListView.h"
#include "MaterialSelectDialog.h"
#include "ResourceModel.h"
#include "TileSetViewModel.h"
#include "TilePaletteGraphicsView.h"
#include "ui_database_tile_set_view.h"
#include <QHBoxLayout>
#include <QDebug>

DatabaseTileSetView::DatabaseTileSetView(QWidget *parent, ResourceModel *resourceModel, TileSetViewModel *tileSetViewModel) :
    QWidget(parent),
    mUI(new Ui::DatabaseTileSetView),
    mMaterialSelectDialog(new MaterialSelectDialog(this, resourceModel)),
    mTilePaletteGraphicsView(new TilePaletteGraphicsView(this, tileSetViewModel)),
    mTileSetViewModel(tileSetViewModel)
{
    mTilePaletteGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mUI->setupUi(this);
    QObject::connect(mUI->groundAssetSelectButton, SIGNAL(clicked()), this, SLOT(groundAssetSelectButtonClicked()));

    mUI->tilePaletteContainer->layout()->addWidget(mTilePaletteGraphicsView);
}

DatabaseTileSetView::~DatabaseTileSetView() {
}

void DatabaseTileSetView::groundAssetSelectButtonClicked() {
    mMaterialSelectDialog->setResourceType(ResourceModel::ResourceType_TileSet);
    mMaterialSelectDialog->exec();
    mUI->groundAssetLineEdit->setText(mMaterialSelectDialog->mSelectedResourceName);
    mTileSetViewModel->setGround(mMaterialSelectDialog->mSelectedResourceName);
    mTilePaletteGraphicsView->loadPalette();
}
