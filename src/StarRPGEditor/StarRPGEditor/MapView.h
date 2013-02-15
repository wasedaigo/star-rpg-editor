#ifndef MapView_H
#define MapView_H

#include <QWidget>

namespace Ui {
class MapView;
}

class MapView : public QWidget
{
    Q_OBJECT
public:
    explicit MapView(QWidget *parent = 0);
    
private:
    Ui::MapView *ui;
    
};

#endif // MapView_H
