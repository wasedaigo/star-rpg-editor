#include "DatabaseListView.h"
#include "ui_database_list_view.h"

DatabaseListView::DatabaseListView(QWidget *parent) :
    QWidget(parent),
    mUI(new Ui::DatabaseListView)
{
    mUI->setupUi(this);
}

DatabaseListView::~DatabaseListView() {
}
