#include "mapeventlistview.h"
#include "ui_mapeventlistview.h"

MapEventListView::MapEventListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapEventListView)
{
    ui->setupUi(this);
}
