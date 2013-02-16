#include "MaterialDialog.h"
#include "ui_material_dialog.h"

MaterialDialog::MaterialDialog(QWidget *parent, QSharedPointer<ResourceModel> resourceModel) :
    QDialog(parent),
    mUI(new Ui::MaterialDialog),
    mResourceModel(resourceModel)
{
    mUI->setupUi(this);
}

MaterialDialog::~MaterialDialog() {

}
