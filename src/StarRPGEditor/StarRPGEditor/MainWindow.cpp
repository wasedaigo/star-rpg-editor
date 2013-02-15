#include "MainWindow.h"
#include "ui_main_window.h"
#include "MapEventListView.h"
#include "MapTreeView.h"
#include "MapView.h"
#include "tilepaletteview.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mpMapEventListView(new MapEventListView(this)),
    mpTilePaletteView(new TilePaletteView(this)),
    mpMapTreeView(new MapTreeView(this)),
    mpMapView(new MapView(this))
{
    ui->setupUi(this);
    ui->eventListPage->layout()->addWidget(mpMapEventListView);
    ui->palettePage->layout()->addWidget(mpTilePaletteView);
    ui->mapTreeFrame->layout()->addWidget(mpMapTreeView);
    ui->rightContainer->layout()->addWidget(mpMapView);
    ui->stackedWidget->setCurrentIndex(0);
    this->loadStyleSheet();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mpMapEventListView;
    delete mpTilePaletteView;
    delete mpMapTreeView;
    delete mpMapView;
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
