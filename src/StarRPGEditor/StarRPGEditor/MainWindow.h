#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class GameDataModel;
class BaseScene;
class NavigationController;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadStyleSheet();
    BaseScene* createScene(const QString& sceneName);

    QScopedPointer<Ui::MainWindow> mUI;
    NavigationController *mNavigationController;
    GameDataModel *mGameDataModel;
    QWidget *mCurrentScene;

private slots:
    void databaseButtonClicked();
    void backButtonClicked();
    void onScenePushed(const QString& sceneName);
    void onScenePoped();
};

#endif // MAINWINDOW_H
