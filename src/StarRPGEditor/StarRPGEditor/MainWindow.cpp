#include "MainWindow.h"
#include "MapEventListView.h"
#include "MapTreeView.h"
#include "MapView.h"
#include "ResourceModel.h"
#include "MapViewModel.h"
#include "TilePaletteView.h"
#include "DatabaseDialog.h"
#include "ui_main_window.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mUI(new Ui::MainWindow),
    mMapViewModel(new MapViewModel(this)),
    mResourceModel(new ResourceModel(this, "/Users/sato.daigo/Development/git/star-rpg-framework/html/res")),
    mMapEventListView(new MapEventListView(this)),
    mTilePaletteView(new TilePaletteView(this, mResourceModel)),
    mMapTreeView(new MapTreeView(this)),
    mMapView(new MapView(this, mMapViewModel)),
    mDatabaseDialog(new DatabaseDialog(this, mResourceModel))
{
    mUI->setupUi(this);
    mUI->eventListPage->layout()->addWidget(mMapEventListView);
    mUI->palettePage->layout()->addWidget(mTilePaletteView);
    mUI->mapTreeFrame->layout()->addWidget(mMapTreeView);
    mUI->rightContainer->layout()->addWidget(mMapView);
    mUI->stackedWidget->setCurrentIndex(0);
    this->loadStyleSheet();

    QObject::connect(mMapView, SIGNAL(databaseOpen()), this, SLOT(openDatabase()));
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
    mDatabaseDialog->exec();
}
