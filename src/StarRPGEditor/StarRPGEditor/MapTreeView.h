#ifndef MapTreeView_H
#define MapTreeView_H

#include <QWidget>
namespace Ui {
class MapTreeView;
}

class MapTreeView : public QWidget
{
    Q_OBJECT
public:
    explicit MapTreeView(QWidget *parent = 0);
    
private:
    Ui::MapTreeView *ui;
    
};

#endif // MapTreeView_H
