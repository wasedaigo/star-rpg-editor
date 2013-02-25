#include "TileSetViewModel.h"
#include "ResourceModel.h"
#include <QPainter>

static const int TILESET_WIDTH = 256;
TileSetViewModel::TileSetViewModel(QObject *parent, ResourceModel *resourceModel) :
    QObject(parent),
    mResourceModel(resourceModel),
    mAnimeFilename(""),
    mTerrainFilename(""),
    mPlainFilename(""),
    mDstPixmap(NULL),
    mSrcAnimePixmap(NULL),
    mSrcPlainPixmap(NULL),
    mSrcObjectPixmap(NULL),
    mDirty(true)
{
}

void TileSetViewModel::setAnime(const QString& filename)
{
    if (mAnimeFilename != filename) {
        mDirty = true;
        mAnimeFilename = filename;
    }
}

void TileSetViewModel::setTerrain(const QString& filename)
{
    if (mTerrainFilename != filename) {
        mDirty = true;
        mTerrainFilename = filename;
    }

    // Update QPixmap
}

void TileSetViewModel::setPlain(const QString& filename)
{
    if (mPlainFilename != filename) {
        mDirty = true;
        mPlainFilename = filename;
    }
}

QSharedPointer<QPixmap> TileSetViewModel::getPixmap()
{
    // If it requires updating pixmap, update tileset image
    if (mDirty) {
        int totalHeight = 0;
        mSrcPlainPixmap.reset(NULL);
        if (mTerrainFilename != "") {
            mSrcPlainPixmap.reset(new QPixmap(mResourceModel->getRootPath() + "/tmx/images/" + mTerrainFilename));
        }

        if (!mSrcPlainPixmap.isNull()) {
            totalHeight += 1024;
        }

        mDstPixmap.reset(new QPixmap(TILESET_WIDTH, totalHeight));
        mDstPixmap->fill(QColor(0, 0, 0, 0));
        // Draw Ground Map
        if (!mSrcPlainPixmap.isNull()) {
            QPainter pixPaint(mDstPixmap.data());
            pixPaint.drawPixmap(QRect(0, 0, 256, 256), *mSrcPlainPixmap.data(), QRect(0, 0, 256, 256));
            pixPaint.drawPixmap(QRect(0, 256, 256, 256), *mSrcPlainPixmap.data(), QRect(256, 0, 256, 256));
        }
        mDirty = false;
    }

    return mDstPixmap;
}
