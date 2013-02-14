#include "maptreeview.h"
#include "ui_maptreeview.h"

MapTreeView::MapTreeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapTreeView)
{
    ui->setupUi(this);
}
