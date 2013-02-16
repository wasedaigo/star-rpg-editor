#include "MapView.h"
#include "MapViewModel.h"
#include "ui_map_view.h"

MapView::MapView(QWidget *parent, QSharedPointer<MapViewModel> mapViewModel) :
    QWidget(parent),
    mUI(new Ui::MapView),
    mMapViewModel(mapViewModel)
{
    mUI->setupUi(this);
}

MapView::~MapView() {
}
