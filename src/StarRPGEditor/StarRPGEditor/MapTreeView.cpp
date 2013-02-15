#include "MapTreeView.h"
#include "ui_map_tree_view.h"

MapTreeView::MapTreeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTreeView)
{
    ui->setupUi(this);
}
