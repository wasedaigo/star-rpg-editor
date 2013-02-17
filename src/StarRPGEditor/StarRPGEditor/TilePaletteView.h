#ifndef PALETTEVIEW_H
#define PALETTEVIEW_H

#include <QWidget>

namespace Ui {
class TilePaletteView;
}
class ResourceModel;
class QGraphicsScene;
class QPixmap;

class TilePaletteView : public QWidget
{
    Q_OBJECT
public:
    explicit TilePaletteView(QWidget *parent, ResourceModel *resourceModel);
    ~TilePaletteView();

private:
    void loadPalette();
    ResourceModel *mResourceModel;
    QGraphicsScene *mScene;
    QScopedPointer<Ui::TilePaletteView> mUI;
    QScopedPointer<QPixmap> mSrcPixmap;
    QScopedPointer<QPixmap> mPalettePixmap;
};

#endif // PALETTEVIEW_H
