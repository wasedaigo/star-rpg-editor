#include "MapEventListView.h"
#include "ui_map_event_list_view.h"

MapEventListView::MapEventListView(QWidget *parent) :
    QWidget(parent),
    mUI(new Ui::MapEventListView)
{
    mUI->setupUi(this);
}

MapEventListView::~MapEventListView() {

}
