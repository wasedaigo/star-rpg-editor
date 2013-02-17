#include "MaterialSelectDialog.h"
#include "ui_material_select_dialog.h"
#include <QStandardItemModel>
#include <QGraphicsScene>
#include <QDebug>

MaterialSelectDialog::MaterialSelectDialog(QWidget *parent, ResourceModel *resourceModel) :
    QDialog(parent),
    mUI(new Ui::MaterialSelectDialog),
    mPixmap(NULL),
    mResourceModel(resourceModel),
    mListModel(new QStandardItemModel(0, 1, this)),
    mScene(new QGraphicsScene(this)),
    mCurrentResourceType(ResourceModel::ResourceType_None)
{
    mUI->setupUi(this);
    mUI->listView->setModel(mListModel);
    mUI->graphicsView->setScene(mScene);
    mUI->graphicsView->setCacheMode(QGraphicsView::CacheNone);
    QObject::connect(mUI->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(onListviewclicked(QModelIndex)));
}

MaterialSelectDialog::~MaterialSelectDialog() {
}

void MaterialSelectDialog::setResourceType(ResourceModel::ResourceType resourceType) {
    mListModel->clear();
    QStringList filePaths = mResourceModel->getResources(resourceType);
    for (int i = 0; i < filePaths.length(); i++) {
        QStandardItem *pItem = new QStandardItem(filePaths[i]);
        pItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        mListModel->appendRow(pItem);
    }
    mCurrentResourceType = resourceType;

    // Select the first item
    if (filePaths.length() > 0) {
        mUI->listView->selectionModel()->select(mListModel->index(0, 0), QItemSelectionModel::Select);
        setImage(filePaths[0]);
    }
}

void MaterialSelectDialog::onListviewclicked(const QModelIndex& modelIndex) {
    setImage(modelIndex.data().toString());
}

void MaterialSelectDialog::setImage(QString filename) {
    QString dir = mResourceModel->getResourcePath(mCurrentResourceType);
    QString path = dir + "/" + filename;
    mPixmap.reset(new QPixmap(path));
    mScene->clear();
    mScene->addPixmap(*mPixmap.data());

    mUI->graphicsView->setSceneRect(mPixmap->rect());
}
