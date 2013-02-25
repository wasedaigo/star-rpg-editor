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

    // Anime
    mUI->animeComboBox->addItem("None");
    mUI->animeComboBox->addItems(resourceModel->getResources(ResourceModel::ResourceType_TileSet));
    QObject::connect(mUI->animeComboBox, SIGNAL(animeIndexChanged(int)), this, SLOT(animeComboBoxChanged(int)));

    // Terrain
    mUI->terrainComboBox->addItem("None");
    mUI->terrainComboBox->addItems(resourceModel->getResources(ResourceModel::ResourceType_TileSet));
    QObject::connect(mUI->terrainComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(terrainComboBoxChanged(int)));

    // Plain
    mUI->plainComboBox->addItem("None");
    mUI->plainComboBox->addItems(resourceModel->getResources(ResourceModel::ResourceType_TileSet));
    QObject::connect(mUI->plainComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(plainComboBoxChanged(int)));

    mUI->tilePaletteContainer->layout()->addWidget(mTilePaletteGraphicsView);
}

DatabaseTileSetView::~DatabaseTileSetView() {
}

void DatabaseTileSetView::animeComboBoxChanged(int index) {
    QString text = mUI->animeComboBox->currentText();
    mTileSetViewModel->setAnime(text);
    mTilePaletteGraphicsView->loadPalette();
}

void DatabaseTileSetView::terrainComboBoxChanged(int index) {
    QString text = mUI->terrainComboBox->currentText();
    mTileSetViewModel->setTerrain(text);
    mTilePaletteGraphicsView->loadPalette();
}

void DatabaseTileSetView::plainComboBoxChanged(int index) {
    QString text = mUI->plainComboBox->currentText();
    mTileSetViewModel->setPlain(text);
    mTilePaletteGraphicsView->loadPalette();
}
