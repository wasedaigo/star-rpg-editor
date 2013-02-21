#ifndef PALETTEVIEW_H
#define PALETTEVIEW_H

#include <QWidget>

namespace Ui {
class TilePaletteView;
}
class TileSetViewModel;
class TilePaletteGraphicsView;

class TilePaletteView : public QWidget
{
    Q_OBJECT
public:
    explicit TilePaletteView(QWidget *parent, TileSetViewModel *tileSetViewModel);
    ~TilePaletteView();
    void loadPalette();

private:
    TileSetViewModel *mTileSetViewModel;
    QScopedPointer<Ui::TilePaletteView> mUI;
    TilePaletteGraphicsView *mTilePaletteGraphicsView;
};

#endif // PALETTEVIEW_H
