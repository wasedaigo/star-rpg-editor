#ifndef PALETTEVIEW_H
#define PALETTEVIEW_H

#include <QWidget>

namespace Ui {
class TilePaletteView;
}

class TilePaletteView : public QWidget
{
    Q_OBJECT
public:
    explicit TilePaletteView(QWidget *parent = 0);
    ~TilePaletteView();

private:
    void loadPalette();
    Ui::TilePaletteView *ui;
    QPixmap *mpSrcPixmap;
    QPixmap *mpPalettePixmap;
};

#endif // PALETTEVIEW_H
