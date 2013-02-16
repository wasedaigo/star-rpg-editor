#include "MainWindow.h"
#include "MapEventListView.h"
#include "MapTreeView.h"
#include "MapView.h"
#include "MapViewModel.h"
#include "TilePaletteView.h"
#include "ui_main_window.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mUI(new Ui::MainWindow),
    mMapViewModel(new MapViewModel()),
    mMapEventListView(new MapEventListView(this)),
    mTilePaletteView(new TilePaletteView(this)),
    mMapTreeView(new MapTreeView(this)),
    mMapView(new MapView(this, mMapViewModel))
{
    mUI->setupUi(this);
    mUI->eventListPage->layout()->addWidget(mMapEventListView.data());
    mUI->palettePage->layout()->addWidget(mTilePaletteView.data());
    mUI->mapTreeFrame->layout()->addWidget(mMapTreeView.data());
    mUI->rightContainer->layout()->addWidget(mMapView.data());
    mUI->stackedWidget->setCurrentIndex(0);
    this->loadStyleSheet();
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
