#include "MainWindow.h"

#include "GameDataModel.h"
#include "MapViewModel.h"
#include "DatabaseScene.h"
#include "MapEditorScene.h"
#include "ui_main_window.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mUI(new Ui::MainWindow),
    mGameDataModel(new GameDataModel(this)),
    mDatabaseScene(new DatabaseScene(this, mGameDataModel)),
    mMapEditorScene(new MapEditorScene(this, mGameDataModel))
{
    mUI->setupUi(this);

    QObject::connect(mUI->databaseButton, SIGNAL(clicked()), this, SLOT(databaseButtonClicked()));

    mUI->stackedWidget->addWidget(mMapEditorScene);
    mUI->stackedWidget->addWidget(mDatabaseScene);
    mUI->stackedWidget->setCurrentWidget(mMapEditorScene);

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

void MainWindow::databaseButtonClicked() {
    mUI->stackedWidget->setCurrentWidget(mDatabaseScene);
}
