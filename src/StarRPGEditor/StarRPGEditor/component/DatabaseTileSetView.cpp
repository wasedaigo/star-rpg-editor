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

    mUI->groundComboBox->addItem("None");
    mUI->groundComboBox->addItems(resourceModel->getResources(ResourceModel::ResourceType_TileSet));
    QObject::connect(mUI->groundComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(groundComboBoxChanged(int)));

    mUI->tilePaletteContainer->layout()->addWidget(mTilePaletteGraphicsView);
}

DatabaseTileSetView::~DatabaseTileSetView() {
}

void DatabaseTileSetView::groundComboBoxChanged(int index) {
    QString text = mUI->groundComboBox->currentText();
    mTileSetViewModel->setGround(text);
    mTilePaletteGraphicsView->loadPalette();
}
