#ifndef MapEventListView_H
#define MapEventListView_H

#include <QWidget>

namespace Ui {
class MapEventListView;
}

class MapEventListView : public QWidget
{
    Q_OBJECT
public:
    explicit MapEventListView(QWidget *parent = 0);
    ~MapEventListView();

private:
    QScopedPointer<Ui::MapEventListView> mUI;
};

#endif // MapEventListView_H
