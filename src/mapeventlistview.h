#ifndef MAPEVENTLISTVIEW_H
#define MAPEVENTLISTVIEW_H

#include <QWidget>

namespace Ui {
class MapEventListView;
}

class MapEventListView : public QWidget
{
    Q_OBJECT
public:
    explicit MapEventListView(QWidget *parent = 0);
    
private:
    Ui::MapEventListView *ui;
};

#endif // MAPEVENTLISTVIEW_H
