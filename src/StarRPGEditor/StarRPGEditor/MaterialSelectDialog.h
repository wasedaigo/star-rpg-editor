#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>
#include "ResourceModel.h"

namespace Ui {
class MaterialSelectDialog;
}
class QStandardItemModel;
class QGraphicsScene;

class MaterialSelectDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MaterialSelectDialog(QWidget *parent, QSharedPointer<ResourceModel> resourceModel);
    ~MaterialSelectDialog();
    void setResourceType(ResourceModel::ResourceType resourceType);

signals:
    
public slots:
    void onListviewclicked(const QModelIndex& modelIndex);

private:
    void setImage(QString filename);

    QScopedPointer<Ui::MaterialSelectDialog> mUI;
    QSharedPointer<ResourceModel> mResourceModel;
    QScopedPointer<QStandardItemModel> mListModel;
    QScopedPointer<QPixmap> mPixmap;
    QScopedPointer<QGraphicsScene> mScene;
    ResourceModel::ResourceType mCurrentResourceType;
};

#endif // MATERIALDIALOG_H
