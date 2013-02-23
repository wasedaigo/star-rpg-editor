#include "MapTreeView.h"
#include "ui_map_tree_view.h"

MapTreeView::MapTreeView(QWidget *parent) :
    QWidget(parent),
    mUI(new Ui::MapTreeView)
{
    mUI->setupUi(this);
}

MapTreeView::~MapTreeView() {

}
