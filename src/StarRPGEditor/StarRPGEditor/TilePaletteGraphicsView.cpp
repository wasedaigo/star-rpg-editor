#include "TilePaletteGraphicsView.h"
#include "TileSetViewModel.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QPixmap>

TilePaletteGraphicsView::TilePaletteGraphicsView(QWidget *parent, TileSetViewModel *tileSetViewModel) :
    QGraphicsView(parent),
    mTileSetViewModel(tileSetViewModel),
    mScene(new QGraphicsScene(this)),
    mSrcPixmap(new QPixmap()),
    mPalettePixmap(new QPixmap(256, 1024))
{
    this->setScene(mScene);
}

TilePaletteGraphicsView::~TilePaletteGraphicsView()
{
}

void TilePaletteGraphicsView::loadPalette()
{
    mScene->clear();
    mScene->addPixmap(*mTileSetViewModel->getPixmap().data());
}
