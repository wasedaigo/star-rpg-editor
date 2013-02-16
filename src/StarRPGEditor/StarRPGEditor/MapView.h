#ifndef MapView_H
#define MapView_H

#include <QWidget>

namespace Ui {
class MapView;
}

class MapViewModel;
class MapView : public QWidget
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent, QSharedPointer<MapViewModel> mapViewModel);
    ~MapView();

private:
    QScopedPointer<Ui::MapView> mUI;
    QSharedPointer<MapViewModel> mMapViewModel;

signals:
    void databaseOpen();
};

#endif // MapView_H
