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
    void setGround(const QString& filename);
    void setObject(const QString& filename);
    QSharedPointer<QPixmap> getPixmap();

signals:

private:
    ResourceModel *mResourceModel;
    QString mAnimeFilename;
    QString mGroundFilename;
    QString mObjectFilename;
    QSharedPointer<QPixmap> mDstPixmap;
    QScopedPointer<QPixmap> mSrcAnimePixmap;
    QScopedPointer<QPixmap> mSrcGroundPixmap;
    QScopedPointer<QPixmap> mSrcObjectPixmap;
    bool mDirty;
};

#endif // TILESETVIEWMODEL_H
