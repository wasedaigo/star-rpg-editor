#ifndef BASESCENE_H
#define BASESCENE_H

#include <QWidget>
class NavigationController;
class BaseScene : public QWidget
{
    Q_OBJECT
public:
    explicit BaseScene(QWidget *parent, NavigationController *navigationController);
    virtual ~BaseScene();
    void pushScene(const QString& sceneName);
    void popScene();

private:
    NavigationController *mNavigationController;
};

#endif // BASESCENE_H
