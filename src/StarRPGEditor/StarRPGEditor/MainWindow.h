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

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadStyleSheet();

    QScopedPointer<Ui::MainWindow> mUI;
    QSharedPointer<MapViewModel> mMapViewModel;
    QSharedPointer<ResourceModel> mResourceModel;
    QScopedPointer<MapEventListView> mMapEventListView;
    QScopedPointer<TilePaletteView> mTilePaletteView;
    QScopedPointer<MapTreeView> mMapTreeView;
    QScopedPointer<MapView> mMapView;
    QScopedPointer<DatabaseDialog> mDatabaseDialog;

private slots:
    void openDatabase();
};

#endif // MainWindow_H
