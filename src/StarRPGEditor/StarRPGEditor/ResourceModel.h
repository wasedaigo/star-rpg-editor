#ifndef RESOURCEMODEL_H
#define RESOURCEMODEL_H

#include <QObject>
class ResourceModel : public QObject
{
    Q_OBJECT

public:
    explicit ResourceModel(QObject *parent, QString rootPath);
    void setRootPath(QString rootPath);
    QString getRootPath() const;

private:
    QString mRootPath;
};

#endif // RESOURCEMODEL_H
