#include "ResourceModel.h"

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
