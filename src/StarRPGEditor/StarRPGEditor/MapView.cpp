#include "MapView.h"
#include "ui_map_view.h"

MapView::MapView(QWidget *parent, QSharedPointer<MapViewModel> mapViewModel) :
    QWidget(parent),
    mUI(new Ui::MapView),
    mMapViewModel(mapViewModel)
{
    mUI->setupUi(this);

    // Handle layer buttons
    QObject::connect(mUI->eventButton, SIGNAL(clicked()), this, SLOT(layerEventButtonClicked()));
    QObject::connect(mUI->panoramaButton, SIGNAL(clicked()), this, SLOT(layerPanoramaButtonClicked()));
    QObject::connect(mUI->bottomLayerButton, SIGNAL(clicked()), this, SLOT(layerBottomButtonClicked()));
    QObject::connect(mUI->middleLayerButton, SIGNAL(clicked()), this, SLOT(layerMiddleButtonClicked()));
    QObject::connect(mUI->topLayerButton, SIGNAL(clicked()), this, SLOT(layerTopButtonClicked()));
    QObject::connect(mUI->skyLayerButton, SIGNAL(clicked()), this, SLOT(layerSkyButtonClicked()));

    // Handle zoom buttons
    QObject::connect(mUI->zoom1_1, SIGNAL(clicked()), this, SLOT(zoom1_1ButtonClicked()));
    QObject::connect(mUI->zoom1_2, SIGNAL(clicked()), this, SLOT(zoom1_2ButtonClicked()));
    QObject::connect(mUI->zoom1_4, SIGNAL(clicked()), this, SLOT(zoom1_4ButtonClicked()));
    QObject::connect(mUI->zoom1_8, SIGNAL(clicked()), this, SLOT(zoom1_8ButtonClicked()));

    QObject::connect(mUI->databaseButton, SIGNAL(clicked()), this, SLOT(databaseButtonClicked()));

    layerEventButtonClicked();
    zoom1_1ButtonClicked();
}

MapView::~MapView() {
}

void MapView::layerEventButtonClicked() {
    mUI->eventButton->setChecked(true);
}

void MapView::layerPanoramaButtonClicked() {
    mUI->panoramaButton->setChecked(true);
}

void MapView::layerBottomButtonClicked() {
    mUI->bottomLayerButton->setChecked(true);
}

void MapView::layerMiddleButtonClicked() {
    mUI->middleLayerButton->setChecked(true);
}

void MapView::layerTopButtonClicked() {
    mUI->topLayerButton->setChecked(true);
}

void MapView::layerSkyButtonClicked() {
    mUI->skyLayerButton->setChecked(true);
}

// Handle zoom buttons
void MapView::zoom1_1ButtonClicked() {
    mUI->zoom1_1->setChecked(true);
}

void MapView::zoom1_2ButtonClicked() {
    mUI->zoom1_2->setChecked(true);
}

void MapView::zoom1_4ButtonClicked() {
    mUI->zoom1_4->setChecked(true);
}

void MapView::zoom1_8ButtonClicked() {
    mUI->zoom1_8->setChecked(true);
}

// Open Database Window
void MapView::databaseButtonClicked() {
    emit databaseOpen();
}
