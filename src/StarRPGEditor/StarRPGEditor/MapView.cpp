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

// Handle layer buttons
void MapView::resetAllLayerButtonsState() {
    mUI->eventButton->setChecked(false);
    mUI->panoramaButton->setChecked(false);
    mUI->bottomLayerButton->setChecked(false);
    mUI->middleLayerButton->setChecked(false);
    mUI->topLayerButton->setChecked(false);
    mUI->skyLayerButton->setChecked(false);
}

void MapView::layerEventButtonClicked() {
    this->resetAllLayerButtonsState();
    mUI->eventButton->setChecked(true);
}

void MapView::layerPanoramaButtonClicked() {
    this->resetAllLayerButtonsState();
    mUI->panoramaButton->setChecked(true);
}

void MapView::layerBottomButtonClicked() {
    this->resetAllLayerButtonsState();
    mUI->bottomLayerButton->setChecked(true);
}

void MapView::layerMiddleButtonClicked() {
    this->resetAllLayerButtonsState();
    mUI->middleLayerButton->setChecked(true);
}

void MapView::layerTopButtonClicked() {
    this->resetAllLayerButtonsState();
    mUI->topLayerButton->setChecked(true);
}

void MapView::layerSkyButtonClicked() {
    this->resetAllLayerButtonsState();
    mUI->skyLayerButton->setChecked(true);
}

// Handle zoom buttons
void MapView::resetAllZoomButtonsState() {
    mUI->zoom1_1->setChecked(false);
    mUI->zoom1_2->setChecked(false);
    mUI->zoom1_4->setChecked(false);
    mUI->zoom1_8->setChecked(false);
}

void MapView::zoom1_1ButtonClicked() {
    this->resetAllZoomButtonsState();
    mUI->zoom1_1->setChecked(true);
}

void MapView::zoom1_2ButtonClicked() {
    this->resetAllZoomButtonsState();
    mUI->zoom1_2->setChecked(true);
}

void MapView::zoom1_4ButtonClicked() {
    this->resetAllZoomButtonsState();
    mUI->zoom1_4->setChecked(true);
}

void MapView::zoom1_8ButtonClicked() {
    this->resetAllZoomButtonsState();
    mUI->zoom1_8->setChecked(true);
}

// Open Database Window
void MapView::databaseButtonClicked() {
    emit databaseOpen();
}
