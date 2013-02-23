#include "DatabaseScene.h"
#include "DatabaseListView.h"
#include "DatabaseTileSetView.h"
#include "GameDataModel.h"
#include <QHBoxLayout>
#include "ui_database_scene.h"

DatabaseScene::DatabaseScene(QWidget *parent, GameDataModel *gameDataModel) :
    QWidget(parent),
    mUI(new Ui::DatabaseScene)
{
    mUI->setupUi(this);

    QWidget *pWidget = new QWidget(this);
    QHBoxLayout *pLayout = new QHBoxLayout(this);
    pLayout->addWidget(new DatabaseListView(this));
    pLayout->addWidget(new DatabaseTileSetView(this, gameDataModel->mResourceModel, gameDataModel->mTileSetViewModel));
    pWidget->setLayout(pLayout);

    mUI->tabWidget->addTab(pWidget, "Tile Set");
}

DatabaseScene::~DatabaseScene() {
}
