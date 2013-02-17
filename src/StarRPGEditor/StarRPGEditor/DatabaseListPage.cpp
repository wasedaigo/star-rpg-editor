#include "DatabaseListPage.h"
#include "ui_database_list_page.h"

DatabaseListPage::DatabaseListPage(QWidget *parent) :
    QWidget(parent),
    mUI(new Ui::DatabaseListPage)
{
    mUI->setupUi(this);
}

DatabaseListPage::~DatabaseListPage() {
}
