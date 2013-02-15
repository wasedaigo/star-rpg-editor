#include "tilepaletteview.h"
#include "ui_tile_palette_view.h"
#include <QPainter>
#include <QGraphicsScene>

TilePaletteView::TilePaletteView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TilePaletteView),
    mpSrcPixmap(NULL),
    mpPalettePixmap(NULL)
{
    ui->setupUi(this);
    this->loadPalette();
}

TilePaletteView::~TilePaletteView()
{
    if (mpSrcPixmap != NULL) {
        delete mpSrcPixmap;
    }
    if (mpPalettePixmap != NULL) {
        delete mpPalettePixmap;
    }
}

void TilePaletteView::loadPalette()
{
    mpSrcPixmap = new QPixmap();
    mpSrcPixmap->load("/Users/sato.daigo/Development/git/star-rpg-framework/html/res/tmx/images/tile_a.png");

    mpPalettePixmap = new QPixmap(256, 1024);
    QPainter pixPaint(mpPalettePixmap);
    pixPaint.drawPixmap(QRect(0, 0, 256, 256), *mpSrcPixmap, QRect(0, 0, 256, 256));
    pixPaint.drawPixmap(QRect(0, 256, 256, 256), *mpSrcPixmap, QRect(256, 0, 256, 256));

    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->addPixmap(*mpPalettePixmap);
}
