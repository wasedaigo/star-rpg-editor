#include "NavigationController.h"

NavigationController::NavigationController(QObject *parent)
    : QObject(parent)
{
}

NavigationController::~NavigationController() {
}

void NavigationController::pushScene(const QString& sceneName) {
    emit onScenePushed(sceneName);
}

void NavigationController::popScene() {
    emit onScenePoped();
}
