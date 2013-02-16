#ifndef MapView_H
#define MapView_H

#include <QWidget>
#include "MapViewModel.h"

namespace Ui {
class MapView;
}

class MapView : public QWidget
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent, QSharedPointer<MapViewModel> mapViewModel);
    ~MapView();

private slots:
    void layerEventButtonClicked();
    void layerPanoramaButtonClicked();
    void layerBottomButtonClicked();
    void layerMiddleButtonClicked();
    void layerTopButtonClicked();
    void layerSkyButtonClicked();

    void zoom1_1ButtonClicked();
    void zoom1_2ButtonClicked();
    void zoom1_4ButtonClicked();
    void zoom1_8ButtonClicked();

    void databaseButtonClicked();

private:
    QScopedPointer<Ui::MapView> mUI;
    QSharedPointer<MapViewModel> mMapViewModel;

signals:
    void databaseOpen();
};

#endif // MapView_H
