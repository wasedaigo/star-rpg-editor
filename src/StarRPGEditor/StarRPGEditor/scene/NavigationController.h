#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>

class NavigationController : public QObject
{
    Q_OBJECT
public:
    explicit NavigationController(QObject *parent);
    ~NavigationController();
    void pushScene(const QString& sceneName);
    void popScene();

signals:
    void onScenePushed(const QString& sceneName);
    void onScenePoped();

};

#endif // NAVIGATIONCONTROLLER_H
