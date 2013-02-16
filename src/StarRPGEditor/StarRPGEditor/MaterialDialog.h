#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>
#include "ResourceModel.h"

namespace Ui {
class MaterialDialog;
}
class QStandardItemModel;
class QGraphicsScene;

class MaterialDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MaterialDialog(QWidget *parent, QSharedPointer<ResourceModel> resourceModel);
    ~MaterialDialog();
    void setResourceType(ResourceModel::ResourceType resourceType);

signals:
    
public slots:
    void onListviewclicked(const QModelIndex& modelIndex);

private:
    void setImage(QString filename);

    QScopedPointer<Ui::MaterialDialog> mUI;
    QSharedPointer<ResourceModel> mResourceModel;
    QScopedPointer<QStandardItemModel> mListModel;
    QScopedPointer<QPixmap> mPixmap;
    QScopedPointer<QGraphicsScene> mScene;
    ResourceModel::ResourceType mCurrentResourceType;
};

#endif // MATERIALDIALOG_H
