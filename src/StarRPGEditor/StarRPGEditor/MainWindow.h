#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MapEventListView;
class TilePaletteView;
class MapTreeView;
class MapView;
class MapViewModel;

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
    QScopedPointer<MapEventListView> mMapEventListView;
    QScopedPointer<TilePaletteView> mTilePaletteView;
    QScopedPointer<MapTreeView> mMapTreeView;
    QScopedPointer<MapView> mMapView;
};

#endif // MainWindow_H
