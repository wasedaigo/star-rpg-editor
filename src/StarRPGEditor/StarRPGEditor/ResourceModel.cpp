#include "ResourceModel.h"
#include <QDir>

static QString resourcePath[] = {
    "",
    "tmx/images", // ResourceType_TileSet
    "charaset", //ResourceType_CharaSet
    "picture" //ResourceType_Picture
};

ResourceModel::ResourceModel(QObject *parent, QString rootPath) :
    QObject(parent),
    mRootPath(rootPath)
{
}

void ResourceModel::setRootPath(QString rootPath) {
    mRootPath = rootPath;
}

QString ResourceModel::getRootPath() const {
    return mRootPath;
}

QString ResourceModel::getResourcePath(ResourceType resourceType) const {
    return mRootPath + "/" + resourcePath[resourceType];
}

QStringList ResourceModel::getResources(ResourceType resourceType) const {
    QString path = this->getResourcePath(resourceType);
    QDir dir(path);
    dir.setFilter(QDir::Files);
    QStringList filter;
    filter << "*.png";
    return dir.entryList(filter);
}
