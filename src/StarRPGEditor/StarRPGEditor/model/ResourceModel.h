#ifndef RESOURCEMODEL_H
#define RESOURCEMODEL_H

#include <QObject>
class ResourceModel : public QObject
{
    Q_OBJECT

public:
    enum ResourceType {
        ResourceType_None,
        ResourceType_TileSet,
        ResourceType_CharaSet,
        ResourceType_Picture,
        ResourceType_COUNT
    };

    explicit ResourceModel(QObject *parent);
    void setRootPath(QString rootPath);
    QString getRootPath() const;
    QString getResourcePath(ResourceType resourceType) const;
    QStringList getResources(ResourceType resourceType) const;

private:
    QString mRootPath;
};

#endif // RESOURCEMODEL_H
