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

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadStyleSheet();
    Ui::MainWindow *ui;
    MapEventListView *mpMapEventListView;
    TilePaletteView *mpTilePaletteView;
    MapTreeView *mpMapTreeView;
    MapView *mpMapView;
};

#endif // MainWindow_H
