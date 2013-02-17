#include "DatabaseDialog.h"
#include "DatabaseListPage.h"
#include "ui_database_dialog.h"

DatabaseDialog::DatabaseDialog(QWidget *parent, ResourceModel *resourceModel) :
    QDialog(parent),
    mUI(new Ui::DatabaseDialog),
    mResourceModel(resourceModel)
{
    mUI->setupUi(this);
    mUI->tabWidget->addTab(new DatabaseListPage(this), "Tile Set");
}

DatabaseDialog::~DatabaseDialog() {
}
