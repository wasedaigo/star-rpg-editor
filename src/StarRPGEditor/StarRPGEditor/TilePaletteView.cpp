#include "TilePaletteView.h"
#include "ResourceModel.h"
#include "ui_tile_palette_view.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QPixmap>

TilePaletteView::TilePaletteView(QWidget *parent, QSharedPointer<ResourceModel> resourceModel) :
    QWidget(parent),
    mResourceModel(resourceModel),
    mUI(new Ui::TilePaletteView),
    mSrcPixmap(new QPixmap()),
    mPalettePixmap(new QPixmap(256, 1024)),
    mScene(new QGraphicsScene())
{
    mUI->setupUi(this);
    this->loadPalette();
}

TilePaletteView::~TilePaletteView()
{
}

void TilePaletteView::loadPalette()
{
    mSrcPixmap->load(mResourceModel->getRootPath() + "/tmx/images/tile_a.png");

    QPainter pixPaint(mPalettePixmap.data());
    pixPaint.drawPixmap(QRect(0, 0, 256, 256), *mSrcPixmap.data(), QRect(0, 0, 256, 256));
    pixPaint.drawPixmap(QRect(0, 256, 256, 256), *mSrcPixmap.data(), QRect(256, 0, 256, 256));

    mUI->graphicsView->setScene(mScene.data());
    mScene->addPixmap(*mPalettePixmap.data());
}
