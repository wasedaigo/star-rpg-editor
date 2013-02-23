#ifndef TILEPALETTEGraphicsVIEW_H
#define PALETTEVIEW_H

#include <QGraphicsView>
class TileSetViewModel;
class QPixmap;
class TilePaletteGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit TilePaletteGraphicsView(QWidget *parent, TileSetViewModel *tileSetViewModel);
    ~TilePaletteGraphicsView();

    void loadPalette();
private:
    TileSetViewModel *mTileSetViewModel;
    QGraphicsScene *mScene;
    QScopedPointer<QPixmap> mSrcPixmap;
    QScopedPointer<QPixmap> mPalettePixmap;
};

#endif // TILEPALETTEGraphicsVIEW_H
