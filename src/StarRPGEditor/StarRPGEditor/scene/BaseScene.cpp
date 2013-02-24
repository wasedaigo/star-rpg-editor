#include "BaseScene.h"
#include "NavigationController.h"

BaseScene::BaseScene(QWidget *parent, NavigationController *navigationController) :
    QWidget(parent),
    mNavigationController(navigationController)
{
}

BaseScene::~BaseScene() {
}

void BaseScene::pushScene(const QString& sceneName) {
    mNavigationController->pushScene(sceneName);
}

void BaseScene::popScene() {
    mNavigationController->popScene();
}
