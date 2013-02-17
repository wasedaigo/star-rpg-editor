#ifndef DATABASELISTPAGE_H
#define DATABASELISTPAGE_H

#include <QWidget>

namespace Ui {
class DatabaseListPage;
}

class DatabaseListPage : public QWidget
{
    Q_OBJECT
public:
    explicit DatabaseListPage(QWidget *parent = 0);
    ~DatabaseListPage();

signals:
    
private:
    QScopedPointer<Ui::DatabaseListPage> mUI;
};

#endif // DATABASELISTPAGE_H
