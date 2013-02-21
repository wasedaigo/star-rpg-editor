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

QString MaterialSelectDialog::getNoneSelectionName() {
    return "none";
}

void MaterialSelectDialog::setResourceType(ResourceModel::ResourceType resourceType) {
    mListModel->clear();
    QStringList filePaths = mResourceModel->getResources(resourceType);

    QStandardItem *pItem = new QStandardItem(this->getNoneSelectionName());
    pItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    mListModel->appendRow(pItem);

    for (int i = 0; i < filePaths.length(); i++) {
        QStandardItem *pItem = new QStandardItem(filePaths[i]);
        pItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        mListModel->appendRow(pItem);
    }
    mCurrentResourceType = resourceType;

    // Select the first item
    mUI->listView->selectionModel()->select(mListModel->index(0, 0), QItemSelectionModel::Select);
    mScene->clear();
}

void MaterialSelectDialog::onListviewclicked(const QModelIndex& modelIndex) {
    setImage(modelIndex.data().toString());
}

void MaterialSelectDialog::setImage(QString filename) {
    mScene->clear();
    if (filename == this->getNoneSelectionName()) {
        mSelectedResourceName = "";
        return;
    }

    mSelectedResourceName = filename;
    QString dir = mResourceModel->getResourcePath(mCurrentResourceType);
    QString path = dir + "/" + filename;
    mPixmap.reset(new QPixmap(path));
    mScene->addPixmap(*mPixmap.data());

    mUI->graphicsView->setSceneRect(mPixmap->rect());
}
