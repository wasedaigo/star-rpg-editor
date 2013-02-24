#include "MainWindow.h"

#include "BaseScene.h"
#include "GameDataModel.h"
#include "MapViewModel.h"
#include "DatabaseScene.h"
#include "MapEditorScene.h"
#include "NavigationController.h"
#include "ui_main_window.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mUI(new Ui::MainWindow),
    mNavigationController(new NavigationController(this)),
    mGameDataModel(new GameDataModel(this)),
    mCurrentScene(NULL)
{
    mUI->setupUi(this);

    QObject::connect(mUI->databaseButton, SIGNAL(clicked()), this, SLOT(databaseButtonClicked()));
    QObject::connect(mUI->backButton, SIGNAL(clicked()), this, SLOT(backButtonClicked()));

    QObject::connect(mNavigationController, SIGNAL(onScenePushed(const QString&)), this, SLOT(onScenePushed(const QString&)));
    QObject::connect(mNavigationController, SIGNAL(onScenePoped()), this, SLOT(onScenePoped()));

    this->loadStyleSheet();
    mNavigationController->pushScene("map_editor");
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
    for (int i = 1; i < mUI->stackedWidget->count(); i++) {
        QWidget *child = mUI->stackedWidget->widget(i);
        mUI->stackedWidget->removeWidget(child);
    }

    mNavigationController->pushScene("database");
}

void MainWindow::backButtonClicked() {
    if (mUI->stackedWidget->count() > 1) {
        mNavigationController->popScene();
    }
}

BaseScene* MainWindow::createScene(const QString& sceneName) {
    if (sceneName == "map_editor") {
        return new MapEditorScene(this, mNavigationController, mGameDataModel);
    }

    if (sceneName == "database") {
        return new DatabaseScene(this, mNavigationController, mGameDataModel);
    }
    return NULL;
}

void MainWindow::onScenePushed(const QString& sceneName) {
    mCurrentScene = createScene(sceneName);

    if (mCurrentScene != NULL) {
        mUI->stackedWidget->addWidget(mCurrentScene);
        mUI->stackedWidget->setCurrentWidget(mCurrentScene);
        mCurrentScene->adjustSize();
    }
}

void MainWindow::onScenePoped(){
    mUI->stackedWidget->removeWidget(mCurrentScene);

    mCurrentScene = mUI->stackedWidget->currentWidget();
    if (mCurrentScene != NULL) {
        mUI->stackedWidget->setCurrentWidget(mCurrentScene);
    }
}
