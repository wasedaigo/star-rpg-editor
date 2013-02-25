#ifndef TILESETVIEWMODEL_H
#define TILESETVIEWMODEL_H

#include <QObject>
#include <QPixmap>

class ResourceModel;
class TileSetViewModel : public QObject
{
    Q_OBJECT

public:
    explicit TileSetViewModel(QObject *parent, ResourceModel *resourceModel);

    void setAnime(const QString& filename);
    void setTerrain(const QString& filename);
    void setPlain(const QString& filename);
    QSharedPointer<QPixmap> getPixmap();

signals:

private:
    ResourceModel *mResourceModel;
    QString mAnimeFilename;
    QString mTerrainFilename;
    QString mPlainFilename;
    QSharedPointer<QPixmap> mDstPixmap;
    QScopedPointer<QPixmap> mSrcAnimePixmap;
    QScopedPointer<QPixmap> mSrcPlainPixmap;
    QScopedPointer<QPixmap> mSrcObjectPixmap;
    bool mDirty;
};

#endif // TILESETVIEWMODEL_H
