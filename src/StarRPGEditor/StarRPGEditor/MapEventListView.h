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
    
private:
    Ui::MapEventListView *ui;
};

#endif // MapEventListView_H
