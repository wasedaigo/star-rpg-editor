#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class GameDataModel;
class DatabaseScene;
class MapEditorScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadStyleSheet();

    QScopedPointer<Ui::MainWindow> mUI;
    GameDataModel *mGameDataModel;
    DatabaseScene *mDatabaseScene;
    MapEditorScene *mMapEditorScene;

private slots:
    void databaseButtonClicked();
};

#endif // MAINWINDOW_H
