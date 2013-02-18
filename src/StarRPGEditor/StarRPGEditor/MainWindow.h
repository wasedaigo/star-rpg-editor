#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MapViewModel;
class MapEventListView;
class TilePaletteView;
class MapTreeView;
class MapView;
class DatabaseDialog;
class ResourceModel;
class GameDataModel;

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
    ResourceModel *mResourceModel;
    MapEventListView *mMapEventListView;
    TilePaletteView *mTilePaletteView;
    MapTreeView *mMapTreeView;
    MapView *mMapView;
    DatabaseDialog *mDatabaseDialog;

private slots:
    void openDatabase();
};

#endif // MainWindow_H
