#include "TilePaletteView.h"
#include "TileSetViewModel.h"
#include "TilePaletteGraphicsView.h"
#include "ui_tile_palette_view.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QPixmap>

TilePaletteView::TilePaletteView(QWidget *parent, TileSetViewModel *tileSetViewModel) :
    QWidget(parent),
    mTileSetViewModel(tileSetViewModel),
    mUI(new Ui::TilePaletteView),
    mTilePaletteGraphicsView(new TilePaletteGraphicsView(this, mTileSetViewModel))
{
    mUI->setupUi(this);
    mUI->graphicsViewContainer->layout()->addWidget(mTilePaletteGraphicsView);
}

TilePaletteView::~TilePaletteView()
{
}

void TilePaletteView::loadPalette()
{
    mTilePaletteGraphicsView->loadPalette();
}
