#ifndef PALETTEVIEW_H
#define PALETTEVIEW_H

#include <QWidget>

namespace Ui {
class TilePaletteView;
}
class QGraphicsScene;
class QPixmap;

class TilePaletteView : public QWidget
{
    Q_OBJECT
public:
    explicit TilePaletteView(QWidget *parent = 0);
    ~TilePaletteView();

private:
    void loadPalette();
    QScopedPointer<Ui::TilePaletteView> mUI;
    QScopedPointer<QPixmap> mSrcPixmap;
    QScopedPointer<QPixmap> mPalettePixmap;
    QScopedPointer<QGraphicsScene> mScene;
};

#endif // PALETTEVIEW_H
