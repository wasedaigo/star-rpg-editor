#include "MapEventListView.h"
#include "ui_map_event_list_view.h"

MapEventListView::MapEventListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapEventListView)
{
    ui->setupUi(this);
}
