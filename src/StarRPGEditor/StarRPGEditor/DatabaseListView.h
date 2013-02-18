#ifndef DATABASELISTVIEW_H
#define DATABASELISTVIEW_H

#include <QWidget>

namespace Ui {
class DatabaseListView;
}

class DatabaseListView : public QWidget
{
    Q_OBJECT
public:
    explicit DatabaseListView(QWidget *parent);
    ~DatabaseListView();

signals:
    
private:
    QScopedPointer<Ui::DatabaseListView> mUI;
};

#endif // DATABASELISTVIEW_H
