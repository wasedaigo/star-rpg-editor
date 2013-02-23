#include "TileSetViewModel.h"
#include "ResourceModel.h"
#include <QPainter>

static const int TILESET_WIDTH = 256;
TileSetViewModel::TileSetViewModel(QObject *parent, ResourceModel *resourceModel) :
    QObject(parent),
    mResourceModel(resourceModel),
    mAnimeFilename(""),
    mGroundFilename(""),
    mObjectFilename(""),
    mDstPixmap(NULL),
    mSrcAnimePixmap(NULL),
    mSrcGroundPixmap(NULL),
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

void TileSetViewModel::setGround(const QString& filename)
{
    if (mGroundFilename != filename) {
        mDirty = true;
        mGroundFilename = filename;
    }

    // Update QPixmap
}

void TileSetViewModel::setObject(const QString& filename)
{
    if (mObjectFilename != filename) {
        mDirty = true;
        mObjectFilename = filename;
    }
}

QSharedPointer<QPixmap> TileSetViewModel::getPixmap()
{
    // If it requires updating pixmap, update tileset image
    if (mDirty) {
        int totalHeight = 0;
        mSrcGroundPixmap.reset(NULL);
        if (mGroundFilename != "") {
            mSrcGroundPixmap.reset(new QPixmap(mResourceModel->getRootPath() + "/tmx/images/" + mGroundFilename));
        }

        if (!mSrcGroundPixmap.isNull()) {
            totalHeight += 1024;
        }

        mDstPixmap.reset(new QPixmap(TILESET_WIDTH, totalHeight));
        mDstPixmap->fill(QColor(0, 0, 0, 0));
        // Draw Ground Map
        if (!mSrcGroundPixmap.isNull()) {
            QPainter pixPaint(mDstPixmap.data());
            pixPaint.drawPixmap(QRect(0, 0, 256, 256), *mSrcGroundPixmap.data(), QRect(0, 0, 256, 256));
            pixPaint.drawPixmap(QRect(0, 256, 256, 256), *mSrcGroundPixmap.data(), QRect(256, 0, 256, 256));
        }
        mDirty = false;
    }

    return mDstPixmap;
}
