#include "MaterialDialog.h"
#include "ui_material_dialog.h"
#include <QStandardItemModel>
#include <QGraphicsScene>
#include <QDebug>

MaterialDialog::MaterialDialog(QWidget *parent, QSharedPointer<ResourceModel> resourceModel) :
    QDialog(parent),
    mUI(new Ui::MaterialDialog),
    mResourceModel(resourceModel),
    mListModel(new QStandardItemModel(0, 1, this)),
    mPixmap(NULL),
    mScene(new QGraphicsScene()),
    mCurrentResourceType(ResourceModel::ResourceType_None)
{
    mUI->setupUi(this);
    mUI->listView->setModel(mListModel.data());
    mUI->graphicsView->setScene(mScene.data());
    mUI->graphicsView->setCacheMode(QGraphicsView::CacheNone);
    QObject::connect(mUI->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(onListviewclicked(QModelIndex)));
}

MaterialDialog::~MaterialDialog() {
}

void MaterialDialog::setResourceType(ResourceModel::ResourceType resourceType) {
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

void MaterialDialog::onListviewclicked(const QModelIndex& modelIndex) {
    setImage(modelIndex.data().toString());
}

void MaterialDialog::setImage(QString filename) {
    QString dir = mResourceModel->getResourcePath(mCurrentResourceType);
    QString path = dir + "/" + filename;
    mPixmap.reset(new QPixmap(path));
    mScene->clear();
    mScene->addPixmap(*mPixmap.data());

    mUI->graphicsView->setSceneRect(mPixmap->rect());
}
