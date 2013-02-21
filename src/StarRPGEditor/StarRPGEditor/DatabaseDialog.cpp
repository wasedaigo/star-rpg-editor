#include "DatabaseDialog.h"
#include "DatabaseListView.h"
#include "DatabaseTileSetView.h"
#include "GameDataModel.h"
#include <QHBoxLayout>
#include "ui_database_dialog.h"

DatabaseDialog::DatabaseDialog(QWidget *parent, GameDataModel *gameDataModel) :
    QDialog(parent),
    mUI(new Ui::DatabaseDialog)
{
    mUI->setupUi(this);

    QWidget *pWidget = new QWidget(this);
    QHBoxLayout *pLayout = new QHBoxLayout(this);
    pLayout->addWidget(new DatabaseListView(this));
    pLayout->addWidget(new DatabaseTileSetView(this, gameDataModel->mResourceMadel, gameDataModel->mTileSetViewModel));
    pWidget->setLayout(pLayout);

    mUI->tabWidget->addTab(pWidget, "Tile Set");
}

DatabaseDialog::~DatabaseDialog() {
}
