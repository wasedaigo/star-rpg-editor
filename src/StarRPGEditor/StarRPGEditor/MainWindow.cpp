#include "MainWindow.h"
#include "MapEventListView.h"
#include "MapTreeView.h"
#include "MapView.h"
#include "ResourceModel.h"
#include "MapViewModel.h"
#include "TilePaletteView.h"
#include "MaterialSelectDialog.h"
#include "ui_main_window.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mUI(new Ui::MainWindow),
    mMapViewModel(new MapViewModel()),
    mResourceModel(new ResourceModel(this, "/Users/sato.daigo/Development/git/star-rpg-framework/html/res")),
    mMapEventListView(new MapEventListView(this)),
    mTilePaletteView(new TilePaletteView(this, mResourceModel)),
    mMapTreeView(new MapTreeView(this)),
    mMapView(new MapView(this, mMapViewModel)),
    mMaterialDialog(new MaterialSelectDialog(this, mResourceModel))
{
    mUI->setupUi(this);
    mUI->eventListPage->layout()->addWidget(mMapEventListView.data());
    mUI->palettePage->layout()->addWidget(mTilePaletteView.data());
    mUI->mapTreeFrame->layout()->addWidget(mMapTreeView.data());
    mUI->rightContainer->layout()->addWidget(mMapView.data());
    mUI->stackedWidget->setCurrentIndex(0);
    this->loadStyleSheet();

    QObject::connect(mMapView.data(), SIGNAL(databaseOpen()), this, SLOT(openDatabase()));
}

MainWindow::~MainWindow() {
}

void MainWindow::loadStyleSheet()
{
    QFile qss(":/qss/main.qss");
    qss.open(QFile::ReadOnly);
    if( qss.isOpen() )
    {
        qApp->setStyleSheet( qss.readAll() );
    }
}

void MainWindow::openDatabase() {
    mMaterialDialog->setResourceType(ResourceModel::ResourceType_TileSet);
    mMaterialDialog->exec();
}
